package hw8;
/**
*
* @author OzanGECKIN
*/
public class Hw8 {
	 /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        GTUSet<Integer> set1= new GTUSet<Integer> (20);
        set1.insert(3);
        set1.insert(3);//Can't add 3 to the set again.
        set1.insert(6);   
        set1.insert(15);
        set1.insert(33);
        set1.insert(18);
        GTUVector<Integer> vec1= new GTUVector<Integer> (10);
        vec1.insert(3);
        vec1.insert(3);//3 can add vectore again.
        vec1.insert(25);
        vec1.insert(17);
        vec1.insert(11);
        vec1.insert(14);
        
        System.out.println("Set size: "+set1.size());
        System.out.println("Vector size:"+vec1.size());
        
        vec1.erase(25);
        set1.erase(15);
        
        if(vec1.contains(25))
            System.out.println("The vector contains 25 data.");
        if(set1.contains(18))
            System.out.println("The set contains 18 data.");
        
        
        
        set1.clear();
        if(set1.empty())
            System.out.println("The set has been cleaned");
        vec1.clear();
        if(vec1.empty())
            System.out.println("The vector has been cleaned.");
        
        
       
        GTUSet<String> set2 = new GTUSet<String> (20);
        set2.insert("mouse");
        set2.insert("mouse");//does not add the mouse string again ..
        set2.insert("keyboard");
        set2.insert("scanner");
        set2.insert("printer");
        GTUVector<String> vec2= new GTUVector<String> (10);
        vec2.insert("monitor");
        vec2.insert("speaker");
        vec2.insert("8086");
        vec2.insert("Pentium");
        vec2.insert("Pentium Pro");
        
        
        System.out.println("Set size: "+set2.size());
        System.out.println("Vector size:"+vec2.size());
        
        
        set2.erase("scanner");
        vec2.erase("Pentium");
        
        if(set2.contains("printer"))
            System.out.println("The vector contains'printer' data.");
        if(vec2.contains("Pentium"))
            System.out.println("The set contains 'Pentium' data. ");
        
        set2.clear();
        if(set2.empty())
            System.out.println("The set has been cleaned.");
        vec2.clear();
        if(vec2.empty())
            System.out.println("The vector has been cleaned.");
        
    }
    
}