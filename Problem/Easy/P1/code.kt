/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 02.08.2024 14:20:59
*********************************************/

class Solution {
    fun twoSum(a: IntArray, t: Int): IntArray {
        var seen = HashMap<Int, Int>();

        var ans = IntArray(2);
        run outer@ {
            a.forEachIndexed { i, x -> 
                val w = t - x
                if (seen.containsKey(w)) {
                    ans[0] = seen[w]!!
                    ans[1] = i
                    return@outer
                }
                seen[x] = i
            }
        }

        return ans
    }
}