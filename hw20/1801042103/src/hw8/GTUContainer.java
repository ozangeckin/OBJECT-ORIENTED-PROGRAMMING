package hw8;

import hw8.GTUSet.GTUIterator;
/**
 *
 * @author OzanGECKIN
 */
public abstract class GTUContainer {
    abstract boolean empty();
    abstract int size();
    abstract int max_size();
    abstract boolean insert(Object element);
    abstract boolean erase(Object element);
    abstract void clear();
    abstract GTUIterator iterator();
    abstract boolean contains(Object o);
    
}