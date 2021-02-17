import java.util.Arrays;

public class Main {
    public static void main(String[] args) {
        MazeGenerator mazeGenerator = new MazeGenerator(5);
        mazeGenerator.generateMaze();

        System.out.println("RAW MAZE\n" + mazeGenerator.getRawMaze());
        //System.out.println("SYMBOLIC MAZE\n" + mazeGenerator.getSymbolicMaze());

        Lab mazeLab= new Lab(mazeGenerator.maze);

        mazeLab.solveMaze(0,0);
        mazeLab.show();
        /*//test stare initiala
        System.out.println("Stare Initiala:"+Arrays.toString(mazeLab.resultMaze()));
        mazeLab.setFinalStage(4,4);

        //test stare finala
        System.out.println("Stare Finala:"+Arrays.toString(mazeLab.finalStage));

        //test pentru functia booleana
        System.out.println("E stare finala? "+mazeLab.checkStage(new int[]{2, 2}));*/
    }
}