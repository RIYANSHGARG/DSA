import java.util.Scanner;

public class Video { 
 public String title; 
 public boolean checked=true; 
 int avgrating; 
 public boolean checked() { 
 return checked; 
 } 
 public void rent() { 
 checked=false; 
 } 
 public void returned() { 
 checked=true; 
 System.out.println("Video is returned "); 
 } 
 public int getRating() { 
 if(avgrating>0) { 
 return avgrating; 
 } else{ 
 System.out.println(" Rating is not available"); 
 return 0; 
 } 
 } 
} 
class VideoStore extends Video{ 
 Video v[]=new Video[10]; 
 static int i=0; 
 void addVideo(String title) { 
 v[i]=new Video(); 
 this.title=title; 
 v[i].title=title; 
 i++; 
 System.out.println("Video Added Successfully"); 
 } 
 void checkOut(String title) { 
 for(int k=0;k<i;k++) { 
 if(v[k].title.equalsIgnoreCase(title)){ 
 if(v[k].checked()){ 
 v[k].rent(); 
 System.out.println("Video is rented"); 
 } else{ 
 System.out.println("Sorry Video not available"); 
 } 
 } 
 } 
 } 
 void returnVideo(String title){ 
 if(i==0) { 
 System.out.println("You have no video to return"); 
 } 
 for(int k=0;k<i;k++) { 
 if(v[k].title.equalsIgnoreCase(title)){ 
 v[k].checked=true; 
 } 
 } 
 } 
 public void receiveRating() { 
 if(i==0){ 
 System.out.println("No Video inInventory"); 
 } else{ 
 for(int k=0;k<i;k++) { 
 System.out.println("Enter the rating for movie"+v[k].title); 
 Scanner ob=new Scanner(System.in); 
 v[k].avgrating=ob.nextInt(); 
 } 
 } 
 } 
 public void listInventory(){ 
 if(i==0) { 
 System.out.println("No Video in Inventory"); 
 } 
 else { 
 for(int k=0;k<i;k++) { 
 System.out.println(k+1 +". "+v[k].title+" "+"Rating "+v[k].avgrating+" Availability 
"+v[k].checked()); 
 } 
 } 
 } 
} 
class VideoStoreLauncher { 
 public static void main(String[] args) { 
 System.out.println("Code by: Abhishek Sharma"); 
 System.out.println("UID: 20BCS9162"); 
 VideoStore vs=new VideoStore(); 
 int ch,uCh,aCh; 
 String title,choice; 
 do { 
 System.out.println("=========Menu========="); 
 System.out.println("1. Login as User"); 
 System.out.println("2. Login as Admin"); 
 System.out.println("Enter Your Choice: "); 
 Scanner s=new Scanner(System.in); 
 ch=s.nextInt(); 
 do { 
 switch(ch) { 
 case 1: 
 System.out.println("1. List Inventory"); 
 System.out.println("2. Rent Video"); 
 System.out.println("3. Enter the rating of Video"); 
 System.out.println("4. Return Video"); 
 uCh=s.nextInt(); 
 if(uCh==1) { 
 vs.listInventory(); 
 } 
 else if(uCh==2) { 
 vs.listInventory(); 
 System.out.println("Enter the video Name you want"); 
 title=s.next(); 
 vs.checkOut(title); 
 } 
 else if(uCh==3){ 
 vs.receiveRating(); 
 } 
 else if(uCh==4) { 
 vs.rent(); 
 } 
 else { 
 System.out.println("No such Option is available"); 
 } 
 break; 
 case 2: 
 System.out.println("1. List Inventory"); 
 System.out.println("2. Add Video"); 
 aCh=s.nextInt(); 
 if(aCh==1) { 
 vs.listInventory(); 
 } 
 if(aCh==2) { 
 System.out.println("Enter the name of Video"); 
 title=s.next(); 
 vs.addVideo(title); 
 // vs.listInventory(); 
 } 
 break; 
 default:System.out.println("Sorry Wrong Choice"); 
 } 
 System.out.println("Do you want to repeat yes/no"); 
 choice=s.next(); 
 } while(choice.equalsIgnoreCase("yes")); 
 System.out.println("Want to Return to main Menu yes/no"); 
 choice=s.next(); 
 } while(choice.equalsIgnoreCase("yes")); 
}
}