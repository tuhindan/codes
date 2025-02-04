/* linked list node class:

class Node {
    int data;
    Node next;
    Node(int value) {
        this.value = value;
    }
}

*/
class ReverseListItterative {
    Node reverseList(Node head) {
        Node reverseList = null;
        Node head1 = null;
        Node temp = null;
        while(head != null) {
            temp = reverseList;
            reverseList = head;
            head = head.next;
            reverseList.next = temp;
        }
        return reverseList;
    }
    Node reverseList(Node head) {
        return reverseList(head, null);  
    }
}

class ReverseListRecursive {
    Node reverseList(Node head) {
        return reverseList(head, null);
    }
    Node reverseList(Node head, Node reverselist) {
        if(head == null)
            return reverselist;
        Node temp = head;
        head = head.next;
        temp.next = reverselist;
        return reverseList(head, temp);   
    } 
}
