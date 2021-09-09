package hw8;

import hw8.GTUSet.GTUIterator;
/**
*
* @author OzanGECKIN
* @param <T>
*/
public class GTUVector<T> extends GTUContainer {
    
    protected final int BUFFER_MAX = 100;
    public int top ;//element is used to remove add ..
    protected int capacity;//how many employees will receive ..
    private T[] array;//array where data is stored ..

    public GTUVector() {//if not specified, it is created with the number 10.
        top = -1;
        capacity = 10;
        array = (T[]) new Object[capacity];
        System.out.println("Size : 10 Vector...");
    }

    public GTUVector(int capacity) {
        this.capacity = capacity;
        top = -1;
        array = (T[]) new Object[this.capacity];
        System.out.println("Size : "+capacity+" Vector..");
    }
    public GTUVector(int capacity, int incr)//vectorun size may increase gradually ..
    {
        capacity+=incr;
        this.capacity = capacity;
        top = -1;
        array = (T[]) new Object[this.capacity];
        System.out.println("Size : "+capacity+"Increase amount : "+incr+"Vector..");
    }

    /**
     * checks whether  it is empty
     * @return boolean
     */
     
    @Override
    public boolean empty() {//checks whether it is empty ..
        if(top==-1)
            return true;
        else
            return false;
    }

    /**
     * return size of container
     * @return int
     */
    @Override
    public int size() {
        return top+1;
    }
    /**
     * Shows the maximum capacity
     * @return int
     */

    @Override
    public int max_size() {
        return BUFFER_MAX;
    }
    /**
     * insert element
     * throw exception IllegalArgumentException if current size is greater than capacity
     *@param element 
     */
    @Override
    public boolean insert(Object element) {//to add a new element. False if the successful insert is
        if(top+1>=capacity)
        {
            throw new IllegalArgumentException(Integer.toString((int) element));//hata throw.. 
        }
        else
        {
            top++;
            array[top]=(T) element;
            System.out.println("Vectore "+element+"successfuly added");
            return true;//successfully added
        }
            
    }
    /**
     * deletes element form container
     * @param element
     */
    @Override
    public boolean erase(Object element) {//delete the element gven as a parameter True if successful deleted
        if(top==-1)
        {
            System.out.println("Array is empty");//Since there are no elements in the empty set .
            return false;
        }
            
        else
        {
            for(int i=top;i>=0;i--)
            {
                 if (array[i] == element) {
                     System.out.println("Vectorden "+element+" successfully remove.");
                    for (int j = i; j < top; j++)
                        array[j] = array[j+1];
                    top--;
                    return true;//element found and deleted .True ..
     
                }
                    
                    
            }
        }
        return false;//element not found
    }
    /**
     * clear all content of container
     */
       

    @Override
    public void clear() {//All element delete.
          if(top==-1)
            return;
        else
        {
        array=null;
        top=-1;
        array = (T[]) new Object[capacity];
        }
        System.out.println("Vector is clear.");
    }

    /**
     * Whether the element given as a parameter is included.
     */

    @Override
    public boolean contains(Object o) {//whether it contains if It does not contain false,ıt contains true
         for(int i=top;i>=0;i--)
            {
                if(array[top]==(T) o)
                    return true;            
            }
            return false;
    }

   


     @Override
    public GTUIterator iterator(){
         throw new UnsupportedOperationException("Not supported yet."); //To change body of generated methods, choose Tools | Templates.
    
    
    }
   
    
}