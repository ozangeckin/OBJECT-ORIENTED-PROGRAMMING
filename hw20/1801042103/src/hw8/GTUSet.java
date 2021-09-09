package hw8;

/**
 *
 * @author OzanGECKIN
 * @param <T>
 */
public class GTUSet<T> extends GTUContainer {
        protected final int BUFFER_MAX = 100;
        protected int top ;//add or remove data for current size
        protected int capacity;//the maximum amount of data it can receive
        private T[] array;//array where data is stored
        public GTUSet()//it is accepted as 10 if it is not specified as a parameter.
        {
        top = -1;
        capacity = 10;
        array = (T[]) new Object[capacity];
        System.out.println("Size : 10 Set..");
        }
        public GTUSet(int capacity_) {
        top = -1;
        capacity = capacity_;
        array = (T[]) new Object[capacity];
        System.out.println("Size : "+capacity+" Set..");
        }

  
        /**
         * inner class to iterate container
         */
    
     protected class GTUIterator {//GTUIterator inner class..
         private int curIndex;
         /**
          * no parameter constructor
          * initialize curIndex to -1
          */
         
         public GTUIterator() {//curIndex -1 with start
            curIndex = -1;
        }
         /**
          * one parameter constructor
          * @param i
          */

        private GTUIterator(int i) {//parameter determines instant index
            curIndex = i;
         }
         /**
          *  returns true if this list iterator has more elements when traversing the list in the forward direction
          * @return
          */
        
        public boolean hasNext() {//Does it control whether there is any future ..
            if (curIndex >= top)
                return false;
            
            return true;
        }
        /**
         * returns the next element in the list and advances the cursor position.
         * @return
         */
         public T next() {//sends forward if any
            T temp;
            temp = array[++curIndex]; 
            return temp;
        }
        
    }
     /**
      * checks whether  it is empty
      * @return boolean
      */
    
    public boolean empty() {
        if(top==-1)
            return true;
        else
            return false;
    }

    public int size() {//send size
        return top+1;
    }
    /**
     * Shows the maximum capacity
     * @return int
     */
    
    public int max_size() {
        return BUFFER_MAX;   
    }
    /**
     * insert element
     * throw exception IllegalArgumentException if current size is greater than capacity
     *@param element 
     */
    
    public boolean insert(Object element) {//for add new eleman
        if(top+1>=capacity)
        {
            throw new IllegalArgumentException(Integer.toString((int) element)); //error throw
        }
        else
        {
            for(int i=top;i>=0;i--)
            {
                if(array[top]==(T) element)//if there is the same element,no addition
                    return false;            
            }
            top++;
            array[top]=(T) element;//element was added and returned true.
            System.out.println("Set'e "+element+" successfuly added..");
        }
            return true;
    }
    /**
     * deletes element form container
     * @param element
     */
   
    public boolean erase(Object element) {
        if(top==-1)
        {
            System.out.println("Array is empty");//Could not delete elements in the empty set ..
            return false;
        }
            
        else
        {
            for(int i=top;i>=0;i--)
            {
                 if (array[i] == element) {//elements found and deleted ..
                     System.out.println("Setten "+element+" successfuly remove..");
                    for (int j = i; j < top; j++)
                        array[j] = array[j+1];
                    top--;
                    return true;
     
                }
                    
                    
            }
        }
        return false;
    }
 /**
  * Whether the element given as a parameter is included.
  */
    public boolean contains(Object o) {
            for(int i=top;i>=0;i--)
            {
                if(array[top]== o)
                    return true;            
            }
            return false;
            
    }

     /**
     * clear all content of container
     */
       
    public void clear() {//to delete all elements.
  
        if(top==-1)//The cluster is already empty
            return;
        else
        {
        array=null;//deleted
        top=-1;
        array = (T[]) new Object[capacity];
        
        }
        
    }
    
    public GTUIterator iterator() {
      
        return new GTUIterator(0);
    }

   
    
}