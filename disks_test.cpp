///////////////////////////////////////////////////////////////////////////////
// disks_test.cpp
//
// Unit tests for disks.hpp
//
///////////////////////////////////////////////////////////////////////////////

#include <cassert>
#include "rubrictest.hpp"
#include "disks.hpp"

int main() {

  Rubric rubric;

  const disk_state alt_one(1), alt_three(3);

  auto sorted_one(alt_one);    
    //  std::cout << sorted_one.to_string() << std::endl;

 auto sorted_three(alt_three); // => LD LD LD
  sorted_three.swap(1);         // => LL DD LD
  sorted_three.swap(3);         // => LL DL DD
  sorted_three.swap(2);         // => LL LD DD
  
  rubric.criterion("disk_state still works", 1,
		   [&]() {
		     TEST_EQUAL("total_count() for n=1", 2, alt_one.total_count());
         TEST_EQUAL("light_count() for n=1", 1, alt_one.light_count());
         TEST_EQUAL("dark_count() for n=1", 1, alt_one.dark_count());
         TEST_TRUE("is_index(0) for n=1", alt_one.is_index(0));
         TEST_TRUE("is_index(1) for n=1", alt_one.is_index(1));
         TEST_FALSE("is_index(2) for n=1", alt_one.is_index(2));
         TEST_EQUAL("get(0) for n=1", DISK_LIGHT, alt_one.get(0));
         TEST_EQUAL("get(1) for n=1", DISK_DARK, alt_one.get(1));

         TEST_EQUAL("total_count() for n=3", 6, alt_three.total_count());
         TEST_EQUAL("light_count() for n=3", 3, alt_three.light_count());
         TEST_EQUAL("dark_count() for n=3", 3, alt_three.dark_count());
         TEST_TRUE("is_index(0) for n=3", alt_three.is_index(0));
         TEST_TRUE("is_index(1) for n=3", alt_three.is_index(1));
         TEST_TRUE("is_index(2) for n=3", alt_three.is_index(2));
         TEST_TRUE("is_index(3) for n=3", alt_three.is_index(3));
         TEST_TRUE("is_index(4) for n=3", alt_three.is_index(4));
         TEST_TRUE("is_index(5) for n=3", alt_three.is_index(5));
         TEST_FALSE("is_index(6) for n=3", alt_three.is_index(6));
         TEST_EQUAL("get(0) for n=3", DISK_LIGHT, alt_three.get(0));
         TEST_EQUAL("get(1) for n=3", DISK_DARK, alt_three.get(1));
         TEST_EQUAL("get(2) for n=3", DISK_LIGHT, alt_three.get(2));
         TEST_EQUAL("get(3) for n=3", DISK_DARK, alt_three.get(3));
         TEST_EQUAL("get(4) for n=3", DISK_LIGHT, alt_three.get(4));
         TEST_EQUAL("get(5) for n=3", DISK_DARK, alt_three.get(5));

         TEST_EQUAL("get(0) after swaps", DISK_LIGHT, sorted_three.get(0));
         TEST_EQUAL("get(1) after swaps", DISK_LIGHT, sorted_three.get(1));
         TEST_EQUAL("get(2) after swaps", DISK_LIGHT, sorted_three.get(2));
         TEST_EQUAL("get(3) after swaps", DISK_DARK, sorted_three.get(3));
         TEST_EQUAL("get(4) after swaps", DISK_DARK, sorted_three.get(4));
         TEST_EQUAL("get(5) after swaps", DISK_DARK, sorted_three.get(5)); 
         
		   });

  rubric.criterion("sorted_disks still works", 1,
		   [&]() {
         auto temp = sorted_disks(alt_three, 13);
         TEST_EQUAL("sorted_disks::after", temp.after(), alt_three);
         TEST_EQUAL("sorted_disks::swap_count", 13, temp.swap_count());
		   });

  rubric.criterion("disk_state::is_initialized", 3,
     		   [&]() {
             TEST_TRUE("is_initialized() for n=1", alt_one.is_initialized());
             TEST_TRUE("is_initialized() for n=1", alt_three.is_initialized());
             TEST_TRUE("is_initialized() after swap", sorted_one.is_initialized());
             TEST_FALSE("is_initialized() after swaps", sorted_three.is_initialized());
           });

  rubric.criterion("disk_state::is_sorted", 3,
     		   [&]() {
             TEST_TRUE("is_sorted() for n=1", alt_one.is_sorted());
             TEST_FALSE("is_sorted() for n=3", alt_three.is_sorted());
             TEST_TRUE("is_sorted() after swap", sorted_one.is_sorted());
             TEST_TRUE("is_sorted() after swaps", sorted_three.is_sorted());
           });

  rubric.criterion("alternate, n=4", 1,
     		   [&]() {
             auto output = sort_alternate(disk_state(4));
             TEST_TRUE("actually sorted", output.after().is_sorted());
             TEST_EQUAL("number of swaps must be 6", 6, output.swap_count());
           });

  rubric.criterion("alternate, n=3", 1,
     		   [&]() {
             auto output = sort_alternate(disk_state(3));
             TEST_TRUE("actually sorted", output.after().is_sorted());
             TEST_EQUAL("number of swaps must be 3", 3, output.swap_count());
           });

  rubric.criterion("alternate, other values", 1,
     		   [&]() {

             auto trial = [](unsigned n) {
               return sort_alternate(disk_state(n)).swap_count();
             };

             TEST_EQUAL("n=10 gives 45 swaps", 45, trial(10));         
             TEST_EQUAL("n=20 gives 190 swaps", 190, trial(20));
             TEST_EQUAL("n=30 gives 435 swaps", 435, trial(30));
             TEST_EQUAL("n=40 gives 780 swaps", 780, trial(40));
             TEST_EQUAL("n=50 gives 1225 swaps", 1225, trial(50));
             TEST_EQUAL("n=60 gives 1770 swaps", 1770, trial(60));
             TEST_EQUAL("n=70 gives 2415 swaps", 2415, trial(70));
             TEST_EQUAL("n=80 gives 3160 swaps", 3160, trial(80));
             TEST_EQUAL("n=90 gives 4005 swaps", 4005, trial(90));
             TEST_EQUAL("n=100 gives 4950 swaps", 4950, trial(100));
           });

  rubric.criterion("lawnmower, n=4", 1,
     		   [&]() {
             auto output = sort_lawnmower(disk_state(4));
             TEST_TRUE("actually sorted", output.after().is_sorted());
             TEST_EQUAL("number of swaps must be 6", 6, output.swap_count());
           });

  rubric.criterion("lawnmower, n=3", 1,
     		   [&]() {
             auto output = sort_lawnmower(disk_state(3));
             TEST_TRUE("actually sorted", output.after().is_sorted());
             TEST_EQUAL("number of swaps must be 3", 3, output.swap_count());
           });

  rubric.criterion("lawnmower, other values", 1,
     		   [&]() {

             auto trial = [](unsigned n) {
               return sort_lawnmower(disk_state(n)).swap_count();
             };

             TEST_EQUAL("n=10 gives 45 swaps", 45, trial(10));
             TEST_EQUAL("n=20 gives 190 swaps", 190, trial(20));
             TEST_EQUAL("n=30 gives 435 swaps", 435, trial(30));
             TEST_EQUAL("n=40 gives 780 swaps", 780, trial(40));
             TEST_EQUAL("n=50 gives 1225 swaps", 1225, trial(50));
             TEST_EQUAL("n=60 gives 1770 swaps", 1770, trial(60));
             TEST_EQUAL("n=70 gives 2415 swaps", 2415, trial(70));
             TEST_EQUAL("n=80 gives 3160 swaps", 3160, trial(80));
             TEST_EQUAL("n=90 gives 4005 swaps", 4005, trial(90));
             TEST_EQUAL("n=100 gives 4950 swaps", 4950, trial(100));
           });

  return rubric.run();
}
