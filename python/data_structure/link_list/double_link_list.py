

class Node():
    # 链表节点
    def __init__(self, item):
        self.prev = None
        # item 是链表存储的数据
        self.elem = item
        # next 下一个数据
        self.next = None


# class DoubleLinkList(single_link_list.SingleLinkList):
class DoubleLinkList():
    def __init__(self, head=None):
        self.__head = head

    """双向链表"""
    def is_empty(self):
        """判断链表是否为空"""
        return self.__head is None

    def length(self):
        """计算链表长度"""
        # cur游标，用来移动遍历节点
        cur = self.__head
        # count 计数
        count = 0
        while cur is not None:
            count += 1
            cur = cur.next
        return count

    def travel(self):
        """遍历链表"""
        # cur游标，用来移动遍历节点
        cur = self.__head
        while cur is not None:
            print(cur.elem, end=' ')
            cur = cur.next
        print(end='\n')

    def add(self, item):
        """在链表头部增加"""
        node = Node(item)
        node.next = self.__head
        self.__head.prev = node
        self.__head = node

    def append(self, item):
        """在链表尾部增加元素,尾差法"""
        node = Node(item)
        if self.__head is None:
            self.__head = node
        else:
            cur = self.__head
            while cur.next is not None:
                cur = cur.next
            cur.next = node
            node.prev = cur

    def insert(self, pos, item):
        """指定位置添加元素
        :param  pos 从0开始
        """
        cur = self.__head
        if pos <= 0:
            self.add(item)
        elif pos > self.length() - 1:
            self.append(item)
        else:
            for i in range(pos):
                cur = cur.next
            node = Node(item)
            node.next = cur
            node.prev = cur.prev
            cur.prev.next = node
            cur.prev = node

    def remove(self, item):
        """删除元素"""
        cur = self.__head
        while cur is not None:
            if cur.elem == item:
                # 搜索点是头节点
                if cur == self.__head:
                    self.__head = cur.next
                    if cur.next:   # 判断链表是否只有一个结点,若只有一个self.__head.prev错误
                        self.__head.prev = None
                else:
                    cur.prev.next = cur.next
                    if cur.next:   # 判断链表是否只有一个结点,若只有一个self.__head.prev错误
                        cur.next.prev = cur.prev
                break
            else:
                cur = cur.next

    def search(self, item):
        """查找元素"""
        cur = self.__head
        while cur is not None:
            if cur.elem == item:
                return True
            else:
                cur = cur.next
        return False


if __name__ == "__main__":
    ll = DoubleLinkList()
    print(ll.is_empty())
    print(ll.length())

    ll.append(1)
    print(ll.is_empty())
    print(ll.length())

    ll.append(2)
    ll.add(8)
    ll.travel()
    ll.append(3)
    ll.travel()
    ll.append(4)
    ll.append(5)
    ll.append(6)
    ll.insert(-1, 9)
    ll.travel()
    ll.insert(3, 100)
    ll.travel()
    ll.insert(10, 200)
    ll.travel()
    ll.remove(9)
    ll.travel()
    ll.remove(200)
    ll.travel()
