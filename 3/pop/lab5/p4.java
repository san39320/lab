class p4{

public static void main(String[] args) {

for(int i=0; i<10000; i++ ) {
p x = new p(i); 
}

System.runFinalization();
System.gc();
 

}
}

class p {

String str;
int id;

p(int i) {
this.str = new String("abcdefghijklmnopqrstuvwxyz");
this.id = i;
}

protected void finalize() {
System.out.println("p class object " + id + " has been finalized.");
}

}
