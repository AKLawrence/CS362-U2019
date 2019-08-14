import junit.framework.TestCase;
import java.io.BufferedReader; 
import java.io.FileReader; 
import java.io.IOException; 

/**
 * Performs unit Tests for url validations.
 *
 * @version $Revision$
 */
 



class BuffRead
{ 
    public static void main(String[] args) throws IOException  
    { 
        FileReader fr = new FileReader("URLS.txt"); 
        BufferedReader br = new BufferedReader(fr); 
        char c[]=new char[100]; 


        if(br.ready()) {  
            System.out.println(br.readLine()); 
  
            //read(char c[], int off, int len) 
            br.read(c); 
            for (int i = 0; i <100 ; i++) { 
            	System.out.print(c[i]); 
            } 
            System.out.println(); 
  
            //reset() BufferedReader for the next line
            br.reset(); 
            
        } 
    } 
}

  /**public class UrlUnitTest extends TestCase {
   *
   *}
   */