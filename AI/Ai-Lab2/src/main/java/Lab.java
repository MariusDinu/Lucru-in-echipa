import java.util.Arrays;

public class Lab {
    public int[][] maze;
    public int[] finalStage=new int[2];
    public int[] startStage=new int[2];
    public int[] lastPosition=new int[2];

    public Lab(int[][] maze) {
        this.maze = maze;
    }

    public void solveMaze(int x, int y) {
        startStage[0]=x;
        startStage[1]=y;
        if (stepMaze(x,y)) {
            maze[x][y]=2;
        }
    }
public boolean stepMaze(int x,int y){
      boolean check ;

   if(maze[x][y]==1)
   {maze[x][y]=2; finalStage[0]=x;finalStage[1]=y;} else return false;


if(x==0 &&y<4)
{
    check = stepMaze(x, y + 1);
    if (check) {
        return true;
    }
    check = stepMaze(x, y - 1);
    if (check) {
        return true;
    }
    check = stepMaze(x + 1, y);
    if (check) {
        return true;
    }
}
else {
    check = stepMaze(x, y - 1);
    if (check) {
        return true;
    }
}
if(y==0 && x<4)
{
    check = stepMaze(x, y + 1);
    if (check) {
        return true;
    }
    check = stepMaze(x + 1, y);
    if (check) {
        return true;
    }
}
if(y==4 && x!=0)
{
    check = stepMaze(x, y - 1);
    if (check) {
        return true;
    }
    check = stepMaze(x - 1, y);
    if (check) {
        return true;
    }


}
if(x<4 && y<4) {
       check = stepMaze(x, y + 1);
       if (check) {
           return true;
       }
       check = stepMaze(x + 1, y);
       if (check) {
           return true;
       }
       check = stepMaze(x, y - 1);
       if (check) {
           return true;
       }
       check = stepMaze(x - 1, y);
       if (check) {
           return true;
       }
   }
   else if(x==4){
       check = stepMaze(x, y + 1);
       if (check) {
           return true;
       }
   }


    return true;}


   /* public boolean checkValid(int a,int b){
        if(maze[a][b]==1)
            return true;
        return false;
    }
*/
    public void setFinalStage(int a,int b){
        finalStage[0]=a;
        finalStage[1]=b;
    }
    public boolean checkStage (int[] actualStage){
      if((actualStage[0]==finalStage[0])&&(actualStage[1]==finalStage[1]))
           return true;
       return false;
    }

public void show() {
    StringBuilder sb = new StringBuilder();
    for (int x = 0; x < 5; x++) {
        for (int y = 0; y < 5; y++) {
            sb.append(maze[x][y]);
            sb.append("  ");

        }
        sb.append("\n");

    } System.out.println(sb.toString());
}
}
