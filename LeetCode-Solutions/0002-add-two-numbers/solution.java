/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
 import java.math.*;
class Solution {
    public String reverse(String str){
        String rstr ="";
        for(int i = str.length()-1; i >= 0; --i){
            rstr += str.charAt(i);
        }
        return rstr;
    }

    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        String num1, num2; num1 = num2 = "";
        //num1
        while(l1 != null){
            num1 += Long.toString(l1.val);
            l1 = l1.next;
        }
        //System.out.println(num1);
        num1 = reverse(num1);
        //num2
        while(l2 != null){
            num2 += Long.toString(l2.val);
            l2 = l2.next;
        }
        //System.out.println(num1);
        num2 = reverse(num2);
        BigInteger Num1 = new BigInteger(num1);
        BigInteger Num2 = new BigInteger(num2);
        BigInteger sum = Num1.add(Num2);
        String result = sum.toString();
        result = reverse(result);
        System.out.println(result);
        ListNode ans;
        if(result.length() > 1)
            { ans = new ListNode((int)(result.charAt(0) - '0'),new ListNode());}
        else
            { ans = new ListNode((int)(result.charAt(0) - '0'),null);}
        ListNode cur = ans.next;
        for(int i = 1; i<result.length(); ++i){
          cur.val = (int)(result.charAt(i) - '0');
          if(i != result.length()-1) cur.next = new ListNode();
          cur = cur.next;
        }
        return ans;
    }
}
