#ifndef BST_H
#define BST_H

#include "TreeNode.h"

template <typename T>
class BST{
    public:
				// lecture 17
        BST();
        virtual ~BST();
        bool iterContains(T d); 
        bool contains(T d); // recursive version that uses recContainsHelper
        void printInOrder(); // least to greatest 
        void printTreePostOrder(); // left tree then right tree then root 
				// lecture 18
        void insert(T d, bool rebuildBool=false);
        int size(); 
        T max(); // right most child
        T min(); // left most child 
        T median(); // will only work if tree is balanced 
        // lecture 19
        T find(T key);
        void remove (T d); 
        void changeData(T data);
         
    private: 
				// lecture 17
        TreeNode<T>* m_root;
        int m_size;
        bool recContainsHelper(TreeNode<T>* n, T d); 
        void printIOHelper(TreeNode<T>* n);
        void printTreePostOrderHelper(TreeNode<T>* subTreeRoot);
				// lecture 18
        void insertHelper(TreeNode<T>*& subTreeRoot, T& d);
        int heightHelper(TreeNode<T>*& subTreeRoot);
        int maxNum(int num1, int num2);

        void rebuild();
        T* m_arr;
        int pos;
        void rebuildHelper(TreeNode<T>* n);
        void medianHelper(T* arr, int low, int high);


        T getMaxHelper(TreeNode<T>* n);
        T getMinHelper(TreeNode<T>* n);
            // lecture 19 
        void findTarget(T key, TreeNode<T>*& target, TreeNode<T>*& parent);
        TreeNode<T>* getSuccessor (TreeNode<T>* rightChild);
     
};


   template <typename T>
        BST<T>::BST(){
        m_root = NULL;
        m_size = 0;
    }

    template <typename T>
    BST<T>::~BST(){
        // TO DO: free up all memory 
    }


    template <typename T>
    bool BST<T>::iterContains(T d){
        if (m_root == NULL){ // tree is empty
            return false; 
        }
        if (m_root -> data == d){ // root is the key d
            return true;
        }

        // look for d 
        bool found = false; 
        TreeNode<T>* current = m_root;
        while (!found){
            // check if d is greater than current go right 
            if (d > current -> m_data){
                current = current -> m_right;
            } else { // if d is less than/ == current go left 
                current = current -> m_left;
            } 
            // check if current node is NULL -> we've reached a leaf and d was not found
            if (current == NULL){
                found =  false; 
                break;
            }

            // check if the current node's data is d -> we found d 
            if (current -> m_data == d){
                found = true;
            }
        }
        return found;
    }

    // RECURSIVE CONTAINS
    template <typename T>
    bool BST<T>::contains(T d){
        return recContainsHelper(m_root, d);
    }

    // RECURSIVE CONTAINS HELPER
    template <typename T>
    bool BST<T>::recContainsHelper( TreeNode<T>* n, T d){
        if (n == NULL){ // if it is null then d is not in tree 
            return false;
        } 
        if (n -> m_data == d) { // if it is not null, is it here? 
            return true;
        }
        if (d > n -> m_data){ // it's not null but it's also not here, check if it is > or <
            return recContainsHelper( n -> m_right, d);
        } else {
            return recContainsHelper( n -> m_left, d);
        }
    }

    template <typename T>
    void BST<T>::printInOrder(){
        printIOHelper(m_root);
    }

    template <typename T>
    void BST<T>::printIOHelper(TreeNode<T>* n){
        if (n != NULL){ // is the node null? 
            printIOHelper(n -> m_left); // if not then print the left thing 
            std::cout << n -> m_data << std::endl; // then print the key of the curr node 
            printIOHelper(n -> m_right); // then print the right thing 
        } 
    }


    template <typename T>
    void BST<T>::printTreePostOrder(){
        printTreePostOrderHelper(m_root);
    }

    template <typename T>
    void BST<T>::printTreePostOrderHelper(TreeNode<T>* subTreeRoot){
        if(subTreeRoot != NULL){
            printTreePostOrderHelper(subTreeRoot->m_left);
            printTreePostOrderHelper(subTreeRoot->m_right);
            std::cout << subTreeRoot->m_data << std::endl;
        }
    }

    template <typename T>
    void BST<T>::insert(T d, bool rebuildBool){
        insertHelper(m_root, d);
        ++m_size;
        // conditions to check if one side of the root is larger than the other side by a factor of 1.5
        if ((m_root->m_leftHeight <= 1 && m_root->m_rightHeight <= 1)){
            return;
        }
        if ((m_root->m_leftHeight == 1 && m_root->m_rightHeight == 2) || (m_root->m_rightHeight == 1 && m_root->m_leftHeight == 2)){
            return;
        }
        if (((m_root->m_leftHeight * 1.5 < m_root->m_rightHeight) && (m_root->m_leftHeight < m_root->m_rightHeight)) && rebuildBool == false){
            rebuild();
        }
        if (((m_root->m_rightHeight * 1.5 < m_root->m_leftHeight) && (m_root->m_leftHeight > m_root->m_rightHeight)) && rebuildBool == false){
            rebuild();
        }
        
    }

    template <typename T>
    void BST<T>::rebuild(){
        m_arr = new T[m_size];
        pos = 0;
        rebuildHelper(m_root);
        int size = m_size;
        for (int i = 0; i < size; i++){ // remove all the nodes
            remove(m_arr[i]);
        }
        medianHelper(m_arr, 0, size);

    }
    // puts all the values in the array, back into the BST sorted by medians, so it's balanced
    template <typename T>
    void BST<T>::medianHelper(T* arr, int low, int high){
        if (high >= low){
            int mid = low + (high - low) / 2;
            if (m_size != 0){
                cout << "not 0" << endl;
                if (contains(arr[mid])){
                    cout << "already exists" << endl;
                    return;
                }
            }
            // first goes to left side of array, then right, and switches the rebuild boolean of the insert method to true, 
            // so it doesn't start rebuilding on itself during the rebuild
            insert(arr[mid], true);
            medianHelper(arr, low, mid - 1);
            medianHelper(arr, mid + 1, high);
        }
        return;
    }

    // puts all the values in BST into the array
    template <typename T>
    void BST<T>::rebuildHelper(TreeNode<T>* n){
        if (n != NULL){ 
            rebuildHelper(n -> m_left); 
            m_arr[pos] = n->m_data;
            pos++;
            rebuildHelper(n -> m_right); 
        }
    }


    template <typename T>
    void BST<T>::insertHelper(TreeNode<T>*& subTreeRoot, T& d){
        if(subTreeRoot == NULL){
            subTreeRoot =  new TreeNode<T>(d); // insert here  & stop recursive call 

        } else if(d > subTreeRoot->m_data){
            insertHelper(subTreeRoot->m_right, d);
            

        } else{ 
            insertHelper(subTreeRoot->m_left, d);
        }
        // The insert method uses recursion to go "down" to the leaf, adds the node, then it updates the heights on the way back "up".
        subTreeRoot->m_leftHeight = heightHelper(subTreeRoot->m_left);
        subTreeRoot->m_rightHeight = heightHelper(subTreeRoot->m_right);
        
    }

    // calculates the height at each node of the tree recursively and updates each node's member variables
    template <typename T>
    int BST<T>::heightHelper(TreeNode<T>*& subTreeRoot){
        if (subTreeRoot == NULL){
            return 0;
        }else{
            int leftHeight = heightHelper(subTreeRoot->m_left);
            int rightHeight = heightHelper(subTreeRoot->m_right);
            return maxNum(leftHeight, rightHeight) + 1;
        }
    }

    // helper method to find the maximum of 2 numbers.
    template <typename T>
    int BST<T>::maxNum(int num1, int num2){
        if (num1 > num2){
            return num1;
        }else{
            return num2;
        }
    }


    // GET SIZE 
    template <typename T>
    int BST<T>::size(){
       return m_size;
    }

    
    // GET MAX 
    template <typename T>
    T BST<T>::max(){
       return getMaxHelper(m_root);
    }

    template <typename T>
    T BST<T>::getMaxHelper(TreeNode<T>* n){
       if(n -> m_right == NULL){
        return n -> m_data;
       } else {
            return getMaxHelper(n -> m_right);
       }
       
    }

    // GET MIN 
    template <typename T>
    T BST<T>::min(){
       return getMinHelper(m_root);
    }

    template <typename T>
    T BST<T>::getMinHelper(TreeNode<T>* n){
       if(n -> m_left == NULL){
            return n -> m_data;
       } else {
            return getMinHelper(n -> m_left);
       }
       
    }

    template <typename T>
    T BST<T>::median(){
        //check if empty we assume it is a non-empty tree
        return m_root->m_data;
    }

    template <typename T>
    void BST<T>::findTarget(T key, TreeNode<T>*& target, TreeNode<T>*& parent){
        // FIND THE NODE WE WANT TO DELETE AND ITS PARENT NODE 
        while (target != NULL && !(target -> m_data == key)){ // while target still has children and it is not our actual target
            parent = target; 
            if (key < target -> m_data){ // if the key is less than the current target node, keep going left
                target = target -> m_left; 
            } else {
                target = target -> m_right;
            }
        }
    }
    template <typename T>
    T BST<T>::find(T key){
        TreeNode<T>*& target = m_root;
        // FIND THE NODE WE WANT TO DELETE AND ITS PARENT NODE 
        while (target != NULL && !(target -> m_data == key)){ // while target still has children and it is not our actual target 
            if (key < target -> m_data){ // if the key is less than the current target node, keep going left
                target = target -> m_left; 
            } else {
                target = target -> m_right;
            }
        }
        return target -> m_data;
    }

    template <typename T>
    TreeNode<T>* BST<T>::getSuccessor (TreeNode<T>* rightChild){
        while (rightChild -> m_left != NULL){ // If the node coming in (rightChild) doesn't have a left child then this is our successor and we're done, else:
            rightChild = rightChild -> m_left;
        }
        return rightChild; // not really (necessarily) a right child, this is the successor! 
    }

    template <typename T>
    void BST<T>::remove(T d){
        // check if tree is empty 
        // we assume the tree is non-empty 
        TreeNode<T>* target = NULL; 
        TreeNode<T>* parent = NULL; 
        target = m_root;

        // find the target 
        findTarget(d, target, parent); // no need save under any variables, target and parent are redefined bc we passed them in by reference  
        
        // target value was not found - it does not exist in our tree
        if (target == NULL){
            return;
        }

        // SCENARIO 1: TARGET IS A LEAF (INCLUDING ROOT)
        if (target -> m_left == NULL && target -> m_right == NULL){
            if (target == m_root){
                m_root = NULL;
            } else { // if it's a leaf but not the root 
                // check if target is its parent's left or right child 
                if (target == parent -> m_left){ // if target is a left child
                    parent -> m_left = NULL;
                } else { // target is a right child 
                    parent -> m_right = NULL;
                }
            }
            delete target;
						-- m_size;
        } 

        // SCENARIO 3: TARGET HAS TWO CHILDREN 
        else if (target -> m_left != NULL && target -> m_right != NULL){  // both children pointers are not null
            TreeNode<T>* suc = getSuccessor(target -> m_right);
            T value = suc -> m_data;
            remove(value); // goes in the BST remove method and removes the node w/ d = value
            target -> m_data = value;
        } 

        // SCENARIO 2: TARGET HAS 1 CHILD 
        else { 
            TreeNode<T>* child;
            // check whether target has a left or right child 
            if (target -> m_left != NULL){ // target has a left child 
                child = target -> m_left;
            } else{                        // target has a right child 
                child = target -> m_right;
            }

            if (target == m_root){
                m_root = child;
            } else {
                if (target == parent -> m_left){ // our target is a left child 
                    parent -> m_left = child; // make the parent's left child the target's child 
                } else {                       // our target is a right child 
                    parent -> m_right = child; // make the parent's right child the target's child 
                }
            }
						target -> m_left = NULL;
						target -> m_right = NULL;

            delete target;
						-- m_size;
        }
       //  --m_size; // TAKE AWAY FROM HERE 
    }

    template <typename T>
    void BST<T>::changeData(T data){
        TreeNode<T>* target = NULL; 
        TreeNode<T>* parent = NULL; 
        target = m_root;
        findTarget(data, target, parent);
        target->m_data = data;
    }



#endif