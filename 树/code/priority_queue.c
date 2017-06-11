#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/**
 * @file priority_queue.c
 * @brief һ������С����ʵ�ֵ����ȶ���
 * @author soulmachine@gmail.com
 */

typedef int heap_elem_t;

/**
 * @struct
 * @brief �ѽṹ�Ķ���
 */
typedef struct heap_t {
	int size;	/* ʵ��Ԫ�صĸ��� */
	int capacity;	/* ���� */
	heap_elem_t *elems;  /* �ѵ����� */
	int(*cmp)(const heap_elem_t*, const heap_elem_t*); /* Ԫ�صıȽϺ��� */
}heap_t;

int
cmp_int(const int *x, const int *y)
{
	const int sub = *x - *y;
	if (sub > 0) return 1;
	else if (sub < 0) return -1;
	else return 0;
}

/**
 * @brief ������
 * @param[in] capacity ��ʼ����
 * @param[in] cmp �ȽϺ���,С�ڷ���-1.���ڷ���0,���ڷ���1
 * @return �ɹ����ضѶ����ָ��,ʧ�ܷ���NULL
 */
heap_t *
heap_create(const int capacity, int(*cmp)(const heap_elem_t*, const heap_elem_t*))
{
	heap_t* h = (heap_t *)malloc(sizeof(heap_t));
	h->size = 0;
	h->capacity = capacity;
	h->elems = (heap_elem_t *)malloc(capacity * sizeof(heap_elem_t));
	h->cmp = cmp;
	return h;
}

/**
 * @brief ���ٶ�
 * @param[inout] h �Ѷ����ָ��
 * @return ��
 */
void
heap_destroy(heap_t *h)
{
	free(h->elems);
	free(h);
}

/**
 * @brief �ж϶��Ƿ�Ϊ��
 * @param[in] h �Ѷ����ָ��
 * @return ���Ϊ��,����1,���򷵻�0
 */
int
heap_empty(heap_t *h)
{
	return h->size == 0;
}

/**
 * @brief ��ȡԪ�صĸ���
 * @param[in] h �Ѷ����ָ��
 * @return Ԫ�صĸ���
 */
int
heap_size(const heap_t *h)
{
	return h->size;
}

/**
 * @brief ���ڶ���startλ��Ԫ�صı仯,�п��ܵ���ԭ�ȶѵ����ʲ���,����Ҫ��startλ�ô���Ԫ��
 * ���������ʵ�λ��,����ά���öѵ�����,����ʵ���������϶��µ������ӽڵ�.
 * @param[in] h �Ѷ����ָ��
 * @param[in] start ��ʼ�ڵ��λ��
 * @return ��
 */
void
heap_sift_down(const heap_t *h, const int start)
{
	int i = start;
	int j;
	const heap_elem_t tmp = h->elems[start];
	/* i�ڵ���ӽڵ�Ϊ 2*i+1 �Լ� 2*i+2 */
	for (j = 2 * i + 1; j < h->size; j = 2 * j + 1) {
		if (j < (h->size - 1) &&
			h->cmp(&(h->elems[j]), &(h->elems[j + 1])) > 0) {
			j++; /* jָ������Ů�е�С�� */
		}
		
		if (h->cmp(&tmp, &(h->elems[j])) <= 0) { /* ���ڵ��ֵС���ӽڵ�Ľ�Сֵ */
			break; /* ����Ҫ���� */
		}
		else {
			h->elems[i] = h->elems[j]; /* �ý�С���ӽڵ㸡��ȥ */
			i = j;
		}
	}
	h->elems[i] = tmp;
}

/**
 * @brief ���ڶ���startλ�ô���Ԫ�ط����˱仯,�п��ܵ��¶ѵ����ʲ���,����Ҫ��startλ�ô�
 * ��Ԫ�ص��������ʵ�λ����ȥ,����ʵ���������¶��ϵ������ӽڵ�.
 * @param[in] h �Ѷ����ָ��
 * @param[in] start ��ʼ�ڵ�
 * @return ��
 */
void
heap_sift_up(const heap_t *h, const int start)
{
	int j = start;	/* j��¼�ӽڵ���±� */
	int i = (j - 1) / 2; /* i��¼���ڵ���±� */
	const heap_elem_t tmp = h->elems[start];

	while (j > 0) {
		if (h->cmp(&(h->elems[i]), &tmp) <= 0) { /* ���ڵ��ֵС���ӽڵ�,����Ҫ���� */
			break;
		}
		else {
			h->elems[j] = h->elems[i];
			j = i;
			i = (i - 1) / 2;
		}
	}
	h->elems[j] = tmp;
}

/**
 * @brief ���������һ��Ԫ��
 * @param[in] h �Ѷ����ָ��
 * @param[in] x Ҫ��ӵ�Ԫ��
 * @return ��
 */
void
heap_push(heap_t *h, const heap_elem_t x)
{
	if (h->size == h->capacity) {
		heap_elem_t * tmp = (heap_elem_t *)
			realloc(h->elems, h->capacity * 2 * sizeof(heap_elem_t));
		h->elems = tmp;
		h->capacity *= 2;
	}
	h->elems[h->size] = x; /* ���¼����Ԫ�ط���ĩβ */
	h->size++;
	heap_sift_up(h, h->size - 1); /* ���¶���ά�ֶѵ����� */
}

/**
 * @brief �����Ѷ���Ԫ��
 * @param[in] h �Ѷ����ָ��
 * @return ��
 */
void
heap_pop(heap_t *h)
{
	h->elems[0] = h->elems[h->size - 1]; /* ��h->elems[0]�Ƴ� */
	h->size--;
	heap_sift_down(h, 0); /* ���϶���ά�ֶѵ����� */
}

/**
 * @brief ��ȡ�Ѷ���Ԫ��
 * @param[in] h �Ѷ����ָ��
 * @return �Ѷ�Ԫ��
 */
heap_elem_t
heap_top(const heap_t *h)
{
	return h->elems[0];
}

int main()
{
	heap_t *h = heap_create(100, cmp_int);
	heap_push(h, 100);
	heap_push(h, 55);
	heap_push(h, 150);
	printf("%d\n", heap_top(h));
	heap_pop(h);
	printf("%d\n", heap_top(h));
	heap_pop(h);
	printf("%d\n", heap_top(h));
	heap_pop(h);
	heap_destroy(h);
	getchar();
}