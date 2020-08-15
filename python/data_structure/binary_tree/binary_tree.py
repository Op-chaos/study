class Node(object):
    """"""
    def __init__(self, item):
        self.elem = item
        self.left_point = None
        self.right_point = None


class Tree(object):
    """二叉树"""
    def __init__(self):
        self.root = None

    def add(self, item):
        node = Node(item)
        if self.root is None:
            self.root = node
            return
        # 广度优先遍历（层次优先）
        # 通过对满二叉树每层队列遍历，决定元素添加的位置
        queue = [self.root]
        # 当队列不为空
        while queue:
            cur_node = queue.pop(0)
            if cur_node.left_point is None:
                cur_node.left_point = node
                return
            else:
                queue.append(cur_node.left_point)

            if cur_node.right_point is None:
                cur_node.right_point = node
                return
            else:
                queue.append(cur_node.right_point)

    def breath_travel(self):
        """广度遍历"""
        if self.root is None:
            return
        # 队列里存放待打印的变量, 该结点被打印时，当该结点的子结点同时被添加到队列，防止连接断开
        queue = [self.root]
        while queue:
            cur_node = queue.pop(0)
            print(cur_node.elem, end=" ")
            if cur_node.left_point is not None:
                queue.append(cur_node.left_point)
            if cur_node.right_point is not None:
                queue.append(cur_node.right_point)

    def preorder(self, tmp_root):
        """先序遍历"""
        if tmp_root is None:
            return
        print(tmp_root.elem, end=" ")
        self.preorder(tmp_root.left_point)
        self.preorder(tmp_root.right_point)

    def inorder(self, tmp_root):
        """中序遍历"""
        if tmp_root is None:
            return
        self.inorder(tmp_root.left_point)
        print(tmp_root.elem, end=" ")
        self.inorder(tmp_root.right_point)

    def postorder(self, tmp_root):
        """中序遍历"""
        if tmp_root is None:
            return
        self.postorder(tmp_root.left_point)
        self.postorder(tmp_root.right_point)
        print(tmp_root.elem, end=" ")


if __name__ == "__main__":
    tree = Tree()
    tree.add(0)
    tree.add(1)
    tree.add(2)
    tree.add(3)
    tree.add(4)
    tree.add(5)
    tree.add(6)
    tree.add(7)
    tree.add(8)
    tree.add(9)
    tree.breath_travel()
    print('')
    tree.preorder(tree.root)
    print('')
    tree.inorder(tree.root)
    print('')
    tree.postorder(tree.root)











