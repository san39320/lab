class node{
	public int processno;
	public int pageno;
	public int frameadress;
	public int status;
	public linkedlist next;
	node(){
	this.processno=-1;
	this.pageno=-1;
	this.frameadress=-1;
	this.next=null;
	this.status=0;
	}
}