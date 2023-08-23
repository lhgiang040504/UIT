def max_result(A):
    A.sort(reverse=True)
    result = A[0]
    sign = 1  # 1 for add, -1 for subtract
    for i in range(1, len(A)):
        if sign == 1:
            result += A[i]
        else:
            result -= A[i]
        sign *= -1  # alternate between add and subtract
        if result < 0:
            break  # stop if result becomes negative
    return result


if(root == NULL) {    return;     }
    stack<Node*> nodeStack;
    nodeStack.push(root);
    while(!nodeStack.empty()) {
        Node* curr = nodeStack.top();
        if (curr -> right == NULL && curr -> left == NULL) {    
            nodeStack.pop();
            cout << curr -> data << " ";
            curr = NULL;
        }
        
        else {
            if (curr -> right != NULL) {    nodeStack.push(curr -> right);    }
            else {    nodeStack.push(curr -> left);    }
        
        }

    }