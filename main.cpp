package javaapplication1;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.util.HashMap;
import javax.swing.JFileChooser;
import javax.swing.filechooser.FileSystemView;

/**
 *
 * @author izab
 */


public class JavaApplication1 {

    /**
     * @param args the command line arguments
     */    
    
    public static void main(String[] args){        
        JFileChooser file = new JFileChooser(FileSystemView.getFileSystemView().getHomeDirectory());
        int returnValue = file.showOpenDialog(null);
        String path = null;
        if(returnValue == JFileChooser.APPROVE_OPTION){
            File selectedFile = file.getSelectedFile();
            path = selectedFile.getAbsolutePath();
            BufferedReader read = null;
            HashMap <String,Integer> licznik = new HashMap<String,Integer>();
            try{
                read = new BufferedReader(new FileReader(path));
                int linia = 0;
                while((linia = read.read())!=-1){                    
                    String uff = String.valueOf((char)linia);
                    if(licznik.containsKey(uff)){
                        int tmp = licznik.get(uff);
                        tmp = tmp +1;
                        licznik.remove(uff);
                        licznik.put(uff, tmp);
                    }
                    else{
                        licznik.put(uff,1);
                    }
                }
            }            
            catch(IOException ex){
              System.out.println("Nie udalo sie otworzyc pliku");  
            }
            finally{
                try{
                    read.close();
                }
                catch(IOException ex){
                    System.out.println("Nie udalo sie zamknac pliku");
                }
            }
            for(String yay : licznik.keySet()){
                String key =yay;
                String value = licznik.get(yay).toString();  
                System.out.println(key + " " + value);  
            }
        }
    }  
}
