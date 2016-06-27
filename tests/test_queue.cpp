#include "queue.hpp"
#include <gtest.h>
typedef float type;


TEST(Queue_on_heap, can_create_queue)
{
	ASSERT_NO_THROW(D_heap_Queue<type> que(10));
}

TEST(Queue_on_heap, cant_create_queue_with_negative_size)
{
	ASSERT_ANY_THROW(D_heap_Queue<type> que(-10));
}

TEST(Queue_on_heap, can_create_copy_of_queue)
{
	D_heap_Queue<type> q(10);
	ASSERT_NO_THROW(D_heap_Queue<type> que(q));
}

TEST(Queue_on_heap, can_create_copy_of_queue_correct)
{
	D_heap_Queue<type> q(10);
	D_heap_Queue<type> que(q);
	EXPECT_NE(&que, &q);
}
////////////////////////////////////////////////////
TEST(Queue_on_heap, can_pop_queue)
{
	D_heap_Queue<type> q(10);
	ASSERT_NO_THROW(q.Pop());
}

TEST(Queue_on_heap, can_pop_queue_correct)
{
	Edge<type> *e = new Edge<type>[3];
	
	e[0].v1 = 10;
	e[0].v2 = 2;
	e[0].key = 8;

	e[1].v1 = 2;
	e[1].v2 = 3;
	e[1].key = 5;

	e[2].v1 = 3;
	e[2].v2 = 4;
	e[2].key = 0;

	D_heap_Queue<type> q(e,3);
	q.Pop();

	Edge<type> *e1 = new Edge<type>[2];
	
	e1[0].v1 = 10;
	e1[0].v2 = 2;
	e1[0].key = 8;

	e1[1].v1 = 2;
	e1[1].v2 = 3;
	e1[1].key = 5;

	D_heap_Queue<type> q1(e1,2);

	EXPECT_EQ(q1,q);
}
////////////////////////////////////////////////////
TEST(Queue_on_heap, can_IsEmpty)
{
	D_heap_Queue<type> q(10);
	ASSERT_NO_THROW(q.IsEmpty());
}

TEST(Queue_on_heap, can_IsEmpty_correct)
{
	D_heap_Queue<type> q(10);
	EXPECT_EQ(q.IsEmpty(),0);
}
//////////////////////////////////////////////////Copy_queue_from_egde
TEST(Queue_on_heap, can_copy_queue_from_egde)
{
	Edge<type> *e = new Edge<type>[5];
	ASSERT_NO_THROW(D_heap_Queue<type> q(e,5));
}

TEST(Queue_on_heap, cant_copy_queue_from_egde_with_negative_size)
{
	Edge<type> *e = new Edge<type>[5];
	ASSERT_ANY_THROW(D_heap_Queue<type> q(e,-5));
}

TEST(Queue_on_heap, cant_copy_queue_from_null_egde)
{
	Edge<type> *e = 0;
	ASSERT_ANY_THROW(D_heap_Queue<type> q(e,5));
}
////////////////////////////////////////////////////
//operator=
TEST(Queue_on_heap, can_assign_queue)
{
	D_heap_Queue<type> q(10);
	D_heap_Queue<type> q1(10);
	ASSERT_NO_THROW(q = q1);
}

TEST(Queue_on_heap, can_assign_queue_with_different_size)
{
	D_heap_Queue<type> q(10);
	D_heap_Queue<type> q1(100);
	ASSERT_NO_THROW(q = q1);
}

TEST(Queue_on_heap, can_assign_queue_with_different_size_corrrect)
{
	D_heap_Queue<type> q(10);
	D_heap_Queue<type> q1(100);
	q = q1;
	EXPECT_EQ(q.GetQsize(), q1.GetQsize());
}
///////////////////////////////////////////////////
//operator==
TEST(Queue_on_heap, can_compare_equal_queues)
{
	D_heap_Queue<type> q(10);
	D_heap_Queue<type> q1(10);
	ASSERT_NO_THROW(q == q1);
}

TEST(Queue_on_heap, compare_equal_queues_return_true)
{
	D_heap_Queue<type> q(10);   //из 0
	D_heap_Queue<type> q1(10);
	EXPECT_TRUE(q == q1);
}

TEST(Queue_on_heap, compare_not_equal_queues_return_false)
{
	D_heap_Queue<type> q(6);   //из 0
	D_heap_Queue<type> q1(10);
	EXPECT_FALSE(q == q1);
}

TEST(Queue_on_heap, compare_queues_with_not_equal_ves_return_false)
{
	Edge<type> *e = new Edge<type>[2];
	e[0].v1 = 10;
	e[0].v2 = 2;
	e[0].key = 7;

	e[1].v1 = 2;
	e[1].v2 = 3;
	e[1].key = 5;

	D_heap_Queue<type> q(e,2);
	Edge<type> *e1 = new Edge<type>[2];
	e1[0].v1 = 10;
	e1[0].v2 = 2;
	e1[0].key = 8;

	e1[1].v1 = 2;
	e1[1].v2 = 3;
	e1[1].key = 5;
	D_heap_Queue<type> q1(e1,2);
	EXPECT_FALSE(q == q1);
}
/////////////////////////////////////////////////////
//operator !=
TEST(Queue_on_heap, can_compare_not_equal_queues)
{
	D_heap_Queue<type> q(3);
	D_heap_Queue<type> q1(10);
	ASSERT_NO_THROW(q != q1);
}

TEST(Queue_on_heap, compare_not_equal_queues_return_true)
{
	D_heap_Queue<type> q(5);   //из 0
	D_heap_Queue<type> q1(10);
	EXPECT_TRUE(q != q1);
}

TEST(Queue_on_heap, compare_equal_queues_return_false)
{
	D_heap_Queue<type> q(10);   //из 0
	D_heap_Queue<type> q1(10);
	EXPECT_FALSE(q != q1);
}

TEST(Queue_on_heap, compare_queues_with_not_equal_ves_return_true)
{
	Edge<type> *e = new Edge<type>[2];
	e[0].v1 = 10;
	e[0].v2 = 2;
	e[0].key = 7;

	e[1].v1 = 2;
	e[1].v2 = 3;
	e[1].key = 5;

	D_heap_Queue<type> q(e,2);
	Edge<type> *e1 = new Edge<type>[2];
	e1[0].v1 = 10;
	e1[0].v2 = 2;
	e1[0].key = 8;

	e1[1].v1 = 2;
	e1[1].v2 = 3;
	e1[1].key = 5;
	D_heap_Queue<type> q1(e1,2);
	EXPECT_TRUE(q != q1);
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
TEST(Queue_on_tree, can_create_queue)
{
	Node<type>*t1 = new Node<type>(10);
	ASSERT_NO_THROW(BSearchTree_Queue<type> *que = new BSearchTree_Queue<type>(10,t1));
}

TEST(Queue_on_tree, cant_create_queue_wiht_null_size)
{
	Node<type> *t1 = new Node<type>(10);
	ASSERT_ANY_THROW(BSearchTree_Queue<type> *que = new BSearchTree_Queue<type>(0,t1));
}

TEST(Queue_on_tree, cant_create_queue_with_negative_size)
{
	Node<type> *t1 = new Node<type>(10);
	ASSERT_ANY_THROW(BSearchTree_Queue<type> *que = new BSearchTree_Queue<type> (-7,t1));
}

TEST(Queue_on_tree, cant_create_queue_with_null_pointer)
{
	ASSERT_ANY_THROW(BSearchTree_Queue<type> *que = new BSearchTree_Queue<type>(7,0));
}
////////////////////////////////////////////////Insert
TEST(Queue_on_tree, can_insert_elem)
{
	Node<type> * t1 = new Node<type>(10);
	Node<type> *t2 = new Node<type>(1);
	BSearchTree_Queue<type> *que = new BSearchTree_Queue<type>(1,t1);
	ASSERT_NO_THROW(que->Insert(t2));
}

TEST(Queue_on_tree, size_more_in_insert_elem)
{
	Node<type> * t1 = new Node<type>(10);
	Node<type> *t2 = new Node<type>(1);
	BSearchTree_Queue<type> *que = new BSearchTree_Queue<type>(1,t1);
	que->Insert(t2);
	EXPECT_EQ(2,que->GetQsize());
}
///////////////////////////////////////////Pop
TEST(Queue_on_tree, can_Pop_elem)
{
	Node<type> * t1 = new Node<type>(10);
	Node<type> *t2 = new Node<type>(1);
	BSearchTree_Queue<type> *que = new BSearchTree_Queue<type>(1,t1);
	que->Insert(t2);
	ASSERT_NO_THROW(que->Pop());
}

TEST(Queue_on_tree, size_less_in_Pop)
{
	Node<type> * t1 = new Node<type>(10);
	Node<type> *t2 = new Node<type>(1);
	BSearchTree_Queue<type> *que = new BSearchTree_Queue<type>(1,t1);
	que->Insert(t2);
	que->Pop();
	EXPECT_EQ(1,que->GetQsize());
}
/////////////////////////////////Top
TEST(Queue_on_tree, can_Top_elem)
{
	Node<type> * t1 = new Node<type>(10);
	Node<type> *t2 = new Node<type>(1);
	BSearchTree_Queue<type> *que = new BSearchTree_Queue<type>(1,t1);
	que->Insert(t2);
	ASSERT_NO_THROW(que->Top());
}

TEST(Queue_on_tree, size_not_change_in_Top)
{
	Node<type> * t1 = new Node<type>(10);
	Node<type> *t2 = new Node<type>(1);
	BSearchTree_Queue<type> *que = new BSearchTree_Queue<type>(1,t1);
	que->Insert(t2);
	que->Top();
	EXPECT_EQ(2,que->GetQsize());
}
////////////////////////////////IsEmpty
TEST(Queue_on_tree, can_IsEmpty)
{
	Node<type> * t1 = new Node<type>(10);
	Node<type> *t2 = new Node<type>(1);
	BSearchTree_Queue<type> *que = new BSearchTree_Queue<type>(1,t1);
	que->Insert(t2);
	ASSERT_NO_THROW(que->IsEmpty());
}

TEST(Queue_on_tree, return_1_when_IsEmpty)
{
	Node<type> * t1 = new Node<type>(10);
	Node<type> *t2 = new Node<type>(1);
	BSearchTree_Queue<type> *que = new BSearchTree_Queue<type>(1,t1);
	que->Insert(t2);
	que->Pop();
	que->Pop();
	EXPECT_EQ(1,que->IsEmpty());
}

TEST(Queue_on_tree, return_0_when_not_IsEmpty)
{
	Node<type> * t1 = new Node<type>(10);
	Node<type> *t2 = new Node<type>(1);
	BSearchTree_Queue<type> *que = new BSearchTree_Queue<type>(1,t1);
	que->Insert(t2);
	que->Pop();
	EXPECT_EQ(0,que->IsEmpty());
}
////////////////////////////////////////print1
TEST(Queue_on_tree, can_print1)
{
	Node<type> * t1 = new Node<type>(10);
	Node<type> *t2 = new Node<type>(1);
	BSearchTree_Queue<type> *que = new BSearchTree_Queue<type>(1,t1);
	que->Insert(t2);
	que->Pop();
	ASSERT_NO_THROW(que->print1());
}

TEST(Queue_on_tree, can_print1_null_que)
{
	Node<type> * t1 = new Node<type>(10);
	BSearchTree_Queue<type> *que = new BSearchTree_Queue<type>(1,t1);
	que->Pop();
	ASSERT_NO_THROW(que->print1());
}
////////////////////////////////////////print2
TEST(Queue_on_tree, can_print2)
{
	Node<type> * t1 = new Node<type>(10);
	Node<type> *t2 = new Node<type>(1);
	BSearchTree_Queue<type> *que = new BSearchTree_Queue<type>(1,t1);
	que->Insert(t2);
	que->Pop();
	ASSERT_NO_THROW(que->print2());
}

TEST(Queue_on_tree, can_print2_null_que)
{
	Node<type> * t1 = new Node<type>(10);
	BSearchTree_Queue<type> *que = new BSearchTree_Queue<type>(1,t1);
	que->Pop();
	ASSERT_NO_THROW(que->print2());
}
/////////////////////////////////////////GetQsize
TEST(Queue_on_tree, can_GetQsize)
{
	Node<type> * t1 = new Node<type>(10);
	Node<type> *t2 = new Node<type>(1);
	BSearchTree_Queue<type> *que = new BSearchTree_Queue<type>(1,t1);
	que->Insert(t2);
	que->Pop();
	ASSERT_NO_THROW(que->GetQsize());
}

TEST(Queue_on_tree, can_GetQsize_correct)
{
	Node<type> * t1 = new Node<type>(10);
	BSearchTree_Queue<type> *que = new BSearchTree_Queue<type>(1,t1);
	que->Pop();
	EXPECT_EQ(0,que->GetQsize());
}
//////////////////////////////////////SetSize
TEST(Queue_on_tree, can_SetQsize)
{
	Node<type> * t1 = new Node<type>(10);
	Node<type> *t2 = new Node<type>(1);
	BSearchTree_Queue<type> *que = new BSearchTree_Queue<type>(1,t1);
	que->Insert(t2);
	ASSERT_NO_THROW(que->SetQsize(2));
}

TEST(Queue_on_tree, cant_Set_negative_size)
{
	Node<type> * t1 = new Node<type>(10);
	Node<type> *t2 = new Node<type>(1);
	BSearchTree_Queue<type> *que = new BSearchTree_Queue<type>(1,t1);
	que->Insert(t2);
	ASSERT_ANY_THROW(que->SetQsize(-2));
}

TEST(Queue_on_tree, can_SetQsize_correct)
{
	Node<type> * t1 = new Node<type>(10);
	Node<type> *t2 = new Node<type>(1);
	BSearchTree_Queue<type> *que = new BSearchTree_Queue<type>(1,t1);
	que->Insert(t2);
	que->SetQsize(2);
	EXPECT_EQ(2,que->GetQsize());
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
TEST(Queue_on_table, can_create_queue)
{
	ASSERT_NO_THROW(SortTable_Queue<type> *que = new SortTable_Queue<type>(10));
}

TEST(Queue_on_table, cant_create_queue_with_negative_size)
{
	ASSERT_ANY_THROW(SortTable_Queue<type> que(-10));
}

TEST(Queue_on_table, can_insert)
{
	SortTable_Queue<type> *q = new SortTable_Queue<type>(10);
	Node<type>* n= new Node<type>(8);
	ASSERT_NO_THROW(q->Insert(n));
}

TEST(Queue_on_table, in_insert_size_is_more)
{
	SortTable_Queue<type> *q = new SortTable_Queue<type>(10);
	Node<type>* n= new Node<type>(8);
	q->Insert(n);
	EXPECT_EQ(1,q->GetQsize());
}

TEST(Queue_on_table, can_pop)
{
	SortTable_Queue<type> *q = new SortTable_Queue<type>(10);
	Node<type>* n= new Node<type>(8);
	q->Insert(n);
	ASSERT_NO_THROW(q->Pop());
}

TEST(Queue_on_table, throw_in_pop_when_que_is_empty)
{
	SortTable_Queue<type> *q = new SortTable_Queue<type>(10);
	ASSERT_ANY_THROW(q->Pop());
}

TEST(Queue_on_table, in_pop_size_decreases)
{
	SortTable_Queue<type> *q = new SortTable_Queue<type>(10);
	Node<type>* n= new Node<type>(8);
	Node<type>* n1= new Node<type>(7);
	q->Insert(n);
	q->Insert(n1);
	q->Pop();
	EXPECT_EQ(1,q->GetQsize());
}

TEST(Queue_on_table, can_IsEmpty)
{
	SortTable_Queue<type> *q = new SortTable_Queue<type>(10);
	Node<type>* n= new Node<type>(8);
	q->Insert(n);
	ASSERT_NO_THROW(q->IsEmpty());
}

TEST(Queue_on_table, IsEmpty_return_true_if_q_is_empty)
{
	SortTable_Queue<type> *q = new SortTable_Queue<type>(10);
	EXPECT_EQ(1,q->IsEmpty());
}

TEST(Queue_on_table, IsEmpty_return_false_if_q_is_not_empty)
{
	SortTable_Queue<type> *q = new SortTable_Queue<type>(10);
	Node<type>* n= new Node<type>(8);
	q->Insert(n);
	EXPECT_EQ(0,q->IsEmpty());
}

TEST(Queue_on_table, can_Top)
{
	SortTable_Queue<type> *q = new SortTable_Queue<type>(10);
	Node<type>* n= new Node<type>(8);
	q->Insert(n);
	ASSERT_NO_THROW(q->Top());
}

TEST(Queue_on_table, throw_in_Top_if_is_empty)
{
	SortTable_Queue<type> *q = new SortTable_Queue<type>(10);
	ASSERT_ANY_THROW(q->Top());
}

TEST(Queue_on_table, can_GetQsize)
{
	SortTable_Queue<type> *q = new SortTable_Queue<type>(10);
	Node<type>* n= new Node<type>(8);
	q->Insert(n);
	ASSERT_NO_THROW(q->GetQsize());
}

TEST(Queue_on_table, can_GetQsize_correct)
{
	SortTable_Queue<type> *q = new SortTable_Queue<type>(10);
	Node<type>* n= new Node<type>(8);
	q->Insert(n);
	EXPECT_EQ(1,q->GetQsize());
}

TEST(Queue_on_table, can_SetQsize)
{
	SortTable_Queue<type> *q = new SortTable_Queue<type>(10);
	Node<type>* n= new Node<type>(8);
	q->Insert(n);
	ASSERT_NO_THROW(q->SetQsize(1));
}

TEST(Queue_on_table, cant_SetQsize_with_negative_size)
{
	SortTable_Queue<type> *q = new SortTable_Queue<type>(10);
	Node<type>* n= new Node<type>(8);
	q->Insert(n);
	ASSERT_ANY_THROW(q->SetQsize(-1));
}