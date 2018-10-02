#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>

#define TEST_ITERATIONS	(10)
#define TEST_LENGTH		(1024 * 1024)
#define PRIME1			(2147483647)
#define PRIME2			(1299709)

/* solution function definition */
void init_editor();
void input_char(char ch);
void input_enter();
void input_backspace();
void input_up(int n);
void input_down(int n);
void input_left(int n);
void input_right(int n);
void get_edit_buffer(char *buf);

int verify(char *data_buf)
{
	int value = 0;
	int i;

	for (i = 0; i < TEST_LENGTH; i ++)
	{
		//putchar(data_buf[i]);
		value = data_buf[i] * PRIME1 + value * PRIME2;
	}

	return value;
}

char data_buf[TEST_LENGTH * 2];
int  data_length;

int test()
{
	data_length = 0;

	init_editor();
	while (data_length < TEST_LENGTH)
	{
		if (rand() % 100 == 1)
		{
			input_enter();
			data_length ++;
		}
		else if (rand() % 100 == 1)
		{
			input_backspace();
		}
		else if (rand() % 100 == 1)
		{
			switch (rand() % 4)
			{
			case 0:
				input_up(rand() % 50);
				break;
			case 1:
				input_down(rand() % 50);
				break;
			case 2:
				input_left(rand() % 50);
				break;
			case 3:
				input_right(rand() % 50);
				break;
			}
		}
		else
		{
			input_char(rand() % 26 + 'A');
			data_length ++; 
		}
	}
	get_edit_buffer(data_buf);
	int value = verify(data_buf);
	printf ("\n%08x\n\n", value);

	return 1;
}

int main()
{
	int i;
	int nr_success = 0;
	int score;

	SYSTEMTIME st_start, st_end;
	GetSystemTime(&st_start);
	
	srand(0xDEADBEEF);
	for (i = 0; i < TEST_ITERATIONS; i ++)
	{
		nr_success += test();
	}

	GetSystemTime(&st_end);
	int exec_sec  = (st_end.wMinute - st_start.wMinute) * 60 + (st_end.wSecond - st_start.wSecond);
	int exec_msec = (st_end.wMilliseconds - st_start.wMilliseconds);
	int exec_time = (exec_sec >= 0) ? exec_sec * 1000 + exec_msec : (60 - exec_sec) * 1000 + exec_msec;

	score = (TEST_ITERATIONS - nr_success) * 1000 * 1000 + exec_time;
	printf("SCORE: %d\n", score);
}

/* ---------------------------------- IMPLEMENT SOLUTION BELOW -------------------------------- */

#define DEFAULT_GAP		(10)	/* malloc not to fail */
#define CUR_BUF_SIZE	(256)

typedef struct line_s
{
	int   length;
	char *buf;
	struct line_s *prev;
	struct line_s *next;
} line_t;

char cur_buf[CUR_BUF_SIZE];
int  cur_buf_length;
int  cursor_offset;
line_t  first_line;
line_t *cur_line;

/* memcpy replacement */
void buf_cpy(char *dest, char *src, int length)
{
	int i;
	for (i = 0; i < length; i ++)
	{
		dest[i] = src[i];
	}
}

void flush_buffer()
{
	char *buf = malloc(cur_line->length + cur_buf_length + DEFAULT_GAP);
	buf_cpy(buf, cur_line->buf, cursor_offset);
	buf_cpy(buf + cursor_offset, cur_buf, cur_buf_length);
	buf_cpy(buf + cursor_offset + cur_buf_length, cur_buf,
		cur_line->length - cursor_offset);
	free(cur_line->buf);
	cur_line->buf = buf;
	cur_line->length += cur_buf_length;
	cursor_offset    += cur_buf_length;
	cur_buf_length = 0;
}

/* @fn    init_editor()
 * @brief �� �׽�Ʈ ������ �ʱ⿡ �ѹ� �Ҹ��� �Լ�
 */
void init_editor()
{
	first_line.length = 0;
	first_line.buf  = malloc(DEFAULT_GAP);
	first_line.prev = NULL;
	first_line.next = NULL;
	cur_line = &first_line;
	cur_buf_length = 0;
	cursor_offset  = 0;
}

/* @fn    input_char()
 * @brief �� ���ڸ� ���� Ŀ����ġ�� ����, Ŀ���� ��ĭ �ڷ� �̷��
 */
void input_char(char ch)
{
	if (cur_buf_length == CUR_BUF_SIZE)
	{
		flush_buffer();
	}

	cur_buf[cur_buf_length] = ch;
	cur_buf_length ++;
}

/* @fn    input_enter()
 * @brief ���� Ŀ�� ��ġ�� ���͸� �����ϰ�,
 *        Ŀ�� �޺κп� �ִ� ���ڿ��� ���� �ٷ� ������.
 */
void input_enter()
{
	line_t *new_line = malloc(sizeof(line_t));

	new_line->length = cur_line->length - cursor_offset;
	new_line->buf    = malloc(new_line->length + DEFAULT_GAP);
	/* manage linked-list */
	new_line->prev   = cur_line;
	new_line->next   = cur_line->next;
	cur_line->next   = new_line;
	if (new_line->next)
	{
		new_line->next->prev = new_line;
	}

	/* copy buffer */
	buf_cpy(new_line->buf, cur_line->buf + cursor_offset, new_line->length);
	cur_line->length = cursor_offset;

	/* append to current buffer */
	flush_buffer();

	/* go to next line */
	cur_line = new_line;
	cursor_offset = 0;
}

/* @fn    input_backspace()
 * @brief Ŀ�� ���� ���� �ϳ��� �����, �޺κ� ���ڿ��� ��ĭ ������ �ű��
 */
void input_backspace()
{
	if (cur_buf_length > 0)	// ���ۿ� �����Ͱ� �ִ� -> ��ĭ ������
	{
		cur_buf_length --;
	}	
	else if (cursor_offset > 0) // ���ۿ� �����ʹ� ����, ������ �߰�
				    //  -> Ŀ�� �޺κ��� ���ڿ��� ���� ����
	{
		buf_cpy(cur_line->buf + cursor_offset - 1,
			cur_line->buf + cursor_offset,
			cur_line->length - cursor_offset);
		cur_line->length --;
		cursor_offset --;
	}
	else if (cur_line->prev != NULL) // ������ �� �� -> ���� ����� ����
	{
		/* merge buffer to prev line */
		line_t *prev_line = cur_line->prev;
		char *buf = malloc(prev_line->length + cur_line->length + DEFAULT_GAP);
		buf_cpy(buf, prev_line->buf, prev_line->length);
		buf_cpy(buf + prev_line->length, cur_line->buf, cur_line->length);
		/* free line buffer */
		free(prev_line->buf);
		free(cur_line->buf);

		/* delete current line */
		prev_line->buf     = buf;
		prev_line->length += cur_line->length;
		prev_line->next    = cur_line->next;
		if (cur_line->next)
		{
			cur_line->next->prev = prev_line;
		}

		/* set prev line to current one */
		free(cur_line);
		cur_line = prev_line;
	}
}

/* @fn    input_up(int n)
 * @brief n��° �� �������� �̵��ϰ�, ������ �� �տ� �ٴٸ��� �� ���忡 Ŀ���� �д�.
 *        �ش� ������ ���̰� ���� Ŀ�� ��ġ���� ª�� ��� ������ �� ������ Ŀ���� �ű��.
 */
void input_up(int n)
{
	flush_buffer();

	while (n > 0)
	{
		if (cur_line->prev)
		{
			cur_line = cur_line->prev;
		}
		n --;
	}

	if (cur_line->length < cursor_offset)
	{
		cursor_offset = cur_line->length;
	}
}

/* @fn    input_down(int n)
 * @brief n��° �� �������� �̵��ϰ�, ������ ���� �ٴٸ��� ������ ���忡 Ŀ���� �д�.
 *        �ش� ������ ���̰� ���� Ŀ�� ��ġ���� ª�� ��� ������ �� ������ Ŀ���� �ű��.
 */
void input_down(int n)
{
	flush_buffer();

	while (n > 0)
	{
		if (cur_line->next)
		{
			cur_line = cur_line->next;
		}
		n --;
	}

	if (cur_line->length < cursor_offset)
	{
		cursor_offset = cur_line->length;
	}
}

/* @fn    input_left(int n)
 * @brief Ŀ���� ���� ��ġ���� n��° �� ���ڷ� �ű��.
 *        ������ �� �տ� �ٴٸ���, ������ ù ���� �տ� Ŀ���� �д�.
 */
void input_left(int n)
{
	flush_buffer();

	cursor_offset = (cursor_offset < n) ? 0 : cursor_offset - n;
}

/* @fn    input_right(int n)
 * @brief Ŀ���� ���� ��ġ���� n��° �� ���ڷ� �ű��.
 *        ������ �� �ڿ� �ٴٸ���, ������ ���� Ŀ���� �д�.
 */
void input_right(int n)
{
	flush_buffer();

	cursor_offset = (cur_line->length < cursor_offset + n) ? cur_line->length : cursor_offset + n;
}

/* @fn    get_edit_buffer(char *buf)
 * @brief �����Ϳ� �ִ� ��� ������ ���ۿ� �����Ѵ�.
 *        �� ������ ������ ���͸� ���ٿ��� ������ �����ؾ� �Ѵ�.
 *        ������ ���忡�� ���͸� ������ �ʴ´�.
 */
void get_edit_buffer(char *buf)
{
	line_t *tmp_line, *next_line;
	int buf_length = 0;
	for (tmp_line = &first_line; tmp_line; tmp_line = tmp_line->next)
	{
		buf_cpy(buf + buf_length, tmp_line->buf, tmp_line->length);
		buf_length += tmp_line->length;
		if (tmp_line->next){
			buf[buf_length ++] = '\n';
		}
	}
	for (; buf_length < TEST_LENGTH; buf_length ++)
	{
		buf[buf_length] = '\0';
	}
	for (tmp_line = first_line.next; tmp_line; tmp_line = next_line)
	{
		next_line = tmp_line->next;
		free(tmp_line->buf);
		free(tmp_line);
	}
}

