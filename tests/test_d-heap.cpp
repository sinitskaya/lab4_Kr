#include "d-heap.hpp"
#include <gtest.h>
typedef float type;

TEST(D_heap, can_create_d_heap)
{
	ASSERT_NO_THROW(D_heap<type> heap(20,2));
}

TEST(D_heap, cant_create_heap_with_too_large_size)
{
	ASSERT_ANY_THROW(D_heap<type> heap(MAX_D_HEAP_SIZE+1,2));
}

TEST(D_heap, cant_create_heap_with_negative_size)
{
	ASSERT_ANY_THROW(D_heap<type> h1(-5,2));
}

TEST(D_heap, can_create_heap_with_size_0)
{
	ASSERT_NO_THROW(D_heap<type> h1(0,2));
}

TEST(D_heap, cant_create_heap_with_negative_d)
{
	ASSERT_ANY_THROW(D_heap<type> h1(5,-2));
}

TEST(D_heap, cant_create_heap_with_d_less_2)
{
	ASSERT_ANY_THROW(D_heap<type> h1(5,1));
}

TEST(D_heap, cant_create_heap_with_d_0)
{
	ASSERT_ANY_THROW(D_heap<type> h1(5,0));
}
///
/*TEST(D_heap, cant_create_heap_with_pointer_0)
{
	int *p=NULL;
	ASSERT_ANY_THROW(D_heap h1(p,0,2));
}

TEST(D_heap, cant_create_heap_with_size_of_pointer_less_then_0)
{
	int *p=new int[0];
	ASSERT_ANY_THROW(D_heap h1(p,-1,2));
}

TEST(D_heap, cant_create_heap_with_incorrect_data)
{
	int *p=NULL;
	ASSERT_ANY_THROW(D_heap h1(p,-6,-2));
}

TEST(D_heap, create_heap_with_pointer_correct)
{
	int s=10;
	int *p=new int[s];
	for (int i=0; i<s; i++)
			p[i] = i;
	D_heap heap(p,10,2);

	D_heap h(10,2);
	for (int i=0; i<10; i++)
		h[i]=i;

	EXPECT_EQ(h,heap);
}*/
///
TEST(D_heap, copied_heap_is_equal_to_source_one)
{
	D_heap<type> h1(5,2);
	for (int i=0; i<h1.size; i++)
		h1.keys[i] = (rand() % 10);
	D_heap<type> h2(h1);
	EXPECT_EQ(h1,h2);
}

TEST(D_heap, copied_heap_hasnt_its_own_memory)
{
	D_heap<type> h1(3,2);
	h1[0] = 1;
	h1[1] = 2;
	h1[2] = 3;
	D_heap<type> h2(h1);
	EXPECT_NE(&h1[0], &h2[0]);
}

TEST(D_heap, copied_heap_has_the_same_size)
{
	D_heap<type> h1(3,2);
	h1[0] = 1;
	h1[1] = 2;
	h1[2] = 3;
	D_heap<type> h2(h1);
	EXPECT_EQ(h1.size,h2.size);
}

TEST(D_heap, copied_heap_has_the_same_d)
{
	D_heap<type> h1(3,2);
	h1[0] = 1;
	h1[1] = 2;
	h1[2] = 3;
	D_heap<type> h2(h1);
	EXPECT_EQ(h1.GetD(),h2.GetD());
}
///GetD
TEST(D_heap, can_get_d)
{
	D_heap<type> h1(5,2);
	ASSERT_NO_THROW(h1.GetD());
}

TEST(D_heap, can_get_d_correct)
{
	D_heap<type> h1(5,2);
	EXPECT_EQ(2,h1.GetD());
}
///Swap
TEST(D_heap,throw_when_swap_elements_with_incorrect_index)
{
	D_heap<type> h(10,2);
	ASSERT_ANY_THROW(h.Swap(-1,-2));
}
///siftUp
TEST(D_heap, can_siftUp)
{
	D_heap<type> h(10,2);
	ASSERT_NO_THROW(h.siftUp(1));
}

TEST(D_heap,throw_when_siftUp_element_with_incorrect_index)
{
	D_heap<type> h(10,2);
	ASSERT_ANY_THROW(h.siftUp(-1));
}
///siftDown
TEST(D_heap, can_siftDown)
{
	D_heap<type> h(10,2);
	ASSERT_NO_THROW(h.siftDown(1));
}

TEST(D_heap,throw_when_siftDown_element_with_incorrect_index)
{
	D_heap<type> h(10,2);
	ASSERT_ANY_THROW(h.siftDown(-1));
}
///MinChild
TEST(D_heap, can_find_MinChild)
{
	D_heap<type> h(5,2);
	ASSERT_NO_THROW(h.MinChild(4));
}

TEST(D_heap, throw_when_incorrect_index_in_find_MinChild)
{
	D_heap<type> h(5,2);
	ASSERT_ANY_THROW(h.MinChild(-4));
}

TEST(D_heap, MinChild_correct)
{
	D_heap<type> h(5,2);
	for (int i=0; i<5; i++)
		h[i]=i;
	EXPECT_EQ(1,h.MinChild(0));
}
///DeleteMinKey
TEST(D_heap, can_DeleteMinKey)
{
	D_heap<type> h(5,2);
	for (int i=0; i<5; i++)
		h[i]=i;
	ASSERT_NO_THROW(h.DeleteMinKey());
}
///DeleteIndex
TEST(D_heap, can_delete_with_index)
{
	D_heap<type> h(5,2);
	for (int i=0; i<5; i++)
		h[i]=i;
	ASSERT_NO_THROW(h.DeleteIndex(0));
}

TEST(D_heap, throw_when_delete_with_incorrect_index)
{
	D_heap<type> h(5,2);
	for (int i=0; i<5; i++)
		h[i]=i;
	ASSERT_ANY_THROW(h.DeleteIndex(-1));
}

TEST(D_heap, throw_when_delete_with_index_bigger_then_size_of_heap)
{
	D_heap<type> h(5,2);
	for (int i=0; i<5; i++)
		h[i]=i;
	ASSERT_ANY_THROW(h.DeleteIndex(6));
}
///Heapify
TEST(D_heap, can_Heapify)
{
	D_heap<type> h(5,2);
	for (int i=0; i<5; i++)
		h[i]=i;
	ASSERT_NO_THROW(h.Heapify());
}
///InsertKey
TEST(D_heap, can_InsertKey)
{
	D_heap<type> h(5,2);
	for (int i=0; i<5; i++)
		h[i]=i;
	ASSERT_NO_THROW(h.InsertKey(8));
}
///Hight
TEST(D_heap, can_cout_up_Hight)
{
	D_heap<type> h(5,2);
	for (int i=0; i<5; i++)
		h[i]=i;
	ASSERT_NO_THROW(h.Hight());
}

TEST(D_heap, cout_up_Hight_correct)
{
	D_heap<type> h(5,2);
	for (int i=0; i<5; i++)
		h[i]=i;
	EXPECT_EQ(3,h.Hight());
}
///IsEmpty
TEST(D_heap, return_1_when_heap_IsEmpty)
{
	D_heap<type> h(0,2);
	EXPECT_EQ(1,h.IsEmpty());
}

TEST(D_heap, return_0_when_heap_Isnt_Empty)
{
	D_heap<type> h(10,2);
	EXPECT_EQ(0,h.IsEmpty());
}
///[]
TEST(D_heap, can_set_and_get_element)
{
  D_heap<type> h(4,2);
  h[0] = 4;
  EXPECT_EQ(4, h[0]);
}

TEST(D_heap, throws_when_set_element_with_negative_index)
{
	D_heap<type> h(5,2);
	ASSERT_ANY_THROW(h[-3] = 1);
}

TEST(D_heap, throws_when_set_element_with_too_large_index)
{
	D_heap<type> h(5,2);
	ASSERT_ANY_THROW(h[10] = 1);
}
///=
TEST(D_heap, can_assign_heap_to_itself)
{
	D_heap<type> h(5,2);
	ASSERT_NO_THROW(h = h);
}

TEST(D_heap, can_assign_heaps_of_equal_size)
{
	D_heap<type> h1(8,3);
	h1[0] = 1;
	h1[1] = 2;
	h1[2] = 3;
	D_heap<type> h2(8,2);
	h1 = h2;
	EXPECT_EQ(h2, h1);
}

TEST(D_heap, can_assign_heaps_of_different_size)
{
	D_heap<type> h1(8,3);
	D_heap<type> h2(5,3);
	h1 = h2;
	ASSERT_NO_THROW(h2 = h1);
}

TEST(D_heap, assign_operator_change_heap_size)
{
	D_heap<type> h1(12,3);
	D_heap<type> h2(8,3);
	h1 = h2;
	EXPECT_EQ(h2.size, h1.size);
}

TEST(D_heap, can_assign_heaps_of_equal_d)
{
	D_heap<type> h1(8,3);
	h1[0] = 1;
	h1[1] = 2;
	h1[2] = 3;
	D_heap<type> h2(5,3);
	h1 = h2;
	EXPECT_EQ(h2, h1);
}

TEST(D_heap, can_assign_heaps_of_different_d)
{
	D_heap<type> h1(8,2);
	D_heap<type> h2(8,3);
	h1 = h2;
	ASSERT_NO_THROW(h2 = h1);
}

TEST(D_heap, assign_operator_change_heap_d)
{
	D_heap<type> h1(8,3);
	D_heap<type> h2(8,2);
	h1 = h2;
	EXPECT_EQ(h2.GetD(), h1.GetD());
}
/// !=
TEST(D_heap, compare_inequality_not_equal_heaps_return_true)
{
	D_heap<type> h(10,2);
	D_heap<type> h1(10,2);
	EXPECT_TRUE(h != h1);
}

TEST(D_heap, compare_inequality_equal_heaps_return_false)
{
	D_heap<type> h(10,2);
	D_heap<type> h1(h);
	EXPECT_FALSE(h != h1);
}
/// ==
TEST(D_heap, compare_equal_heaps_return_true)
{
	D_heap<type> h(10,2);
	D_heap<type> h1(h);
	EXPECT_TRUE(h == h1);
}

TEST(D_heap, compare_not_equal_heaps_return_false)
{
	D_heap<type> h(10,2);
	D_heap<type> h1(10,2);
	EXPECT_FALSE(h == h1);
}
///