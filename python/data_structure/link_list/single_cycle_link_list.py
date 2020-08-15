class Node(object):
    # 链表节点
    def __init__(self, item):
        # item 是链表存储的数据
        self.elem = item
        # next 下一个数据
        self.next = None


class SingleCycleLinkList(object):
    def __init__(self, head=None):
        self.__head = head
        if head:
            self.__head.next = head

    def is_empty(self):
        """判断链表是否为空"""
        return self.__head is None

    def length(self):
        """计算链表长度"""
        if self.is_empty():
            return 0
        # cur游标，用来移动遍历节点
        cur = self.__head
        # count 计数
        count = 1
        while cur.next != self.__head:
            count += 1
            cur = cur.next
        return count

    def travel(self):
        """遍历链表"""
        if self.is_empty():
            return
        # cur游标，用来移动遍历节点
        cur = self.__head
        while cur.next != self.__head:
            print(cur.elem, end=' ')
            cur = cur.next
        # cur 指向尾结点，但未打印
        print(cur.elem, end='\n')

    def add(self, item):
        """在链表头部增加"""
        node = Node(item)
        if self.is_empty():
            self.__head = node
            node.next = node
        else:
            cur = self.__head
            while cur != self.__head:
                cur = cur.next
            node.next = self.__head
            self.__head = node
            cur.next = node

    def append(self, item):
        """在链表尾部增加元素,尾差法"""
        node = Node(item)
        if self.is_empty():
            self.__head = node
            node.next = node
        else:
            cur = self.__head
            while cur.next != self.__head:
                cur = cur.next
            node.next = self.__head
            cur.next = node

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
            node.next = cur.next
            cur.next = node

    def remove(self, item):
        """删除元素"""
        if self.is_empty():
            return False
        cur = self.__head
        while cur.next != self.__head:
            if cur.elem == item:
                # 搜索点是头节点
                if cur == self.__head:
                    rear = self.__head
                    while rear.next != self.__head:
                        rear = rear.next
                    self.__head = cur.next
                    rear.next = self.__head
                # 中间
                else:
                    pre.next = cur.next
                return
            else:
                pre = cur
                cur = cur.next
        # 退出循环
        if cur.elem == item:
            if self.__head == self.__head.next:
                # 链表只有一个结点
                self.__head = None
            else:
                pre.next = cur.next

    def search(self, item):
        """查找元素"""
        if self.is_empty():
            return False
        cur = self.__head
        while cur.next != self.__head:
            if cur.elem == item:
                return True
            else:
                cur = cur.next
        if cur.elem == item:
            return True
        return False


if __name__ == "__main__":
    ll = SingleCycleLinkList()
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
