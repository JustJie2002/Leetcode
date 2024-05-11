/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 05.03.2024 21:46:43
*********************************************/

/**
 * Example:
 * var li = ListNode(5)
 * var v = li.`val`
 * Definition for singly-linked list.
 * class ListNode(var `val`: Int) {
 *     var next: ListNode? = null
 * }
 */
class Solution {
    fun addTwoNumbers(a: ListNode?, b: ListNode?): ListNode? {
        var av = ArrayList<Int>();
        var bv = ArrayList<Int>();

        var a_copy = a;
        while (a_copy != null) {
            av.add(a_copy.val);
            a_copy = a_copy.next;
        }

        println(av);

        var ans = ListNode(0);
        return ans
    }
}

// ~ JustJie