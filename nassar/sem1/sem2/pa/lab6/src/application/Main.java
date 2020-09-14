	package application;
	
import javafx.application.Application;
import javafx.stage.Stage;


public class Main extends Application {
	@Override
	public void start(Stage primaryStage) {
		new MainFrame().setVisible(true);

	}
	
	public static void main(String[] args) {
		launch(args);
		new MainFrame().setVisible(true);

	}
}
