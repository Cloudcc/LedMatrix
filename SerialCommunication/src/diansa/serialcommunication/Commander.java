package diansa.serialcommunication;

import javafx.application.Application;
import javafx.geometry.Insets;
import javafx.scene.Group;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.TextArea;
import javafx.scene.layout.HBox;
import javafx.scene.layout.Pane;
import javafx.stage.Stage;

public class Commander extends Application{

	public static Stage window;
	Scene scene;
	
	public static TextArea outputText;

	@Override
	public void start(Stage primaryStage) throws Exception {
		window = primaryStage;

		SerialTest main = new SerialTest();
		main.initialize();
		
		Button red = new Button("Red");
		Button green = new Button("Green");
		Button blue = new Button("Blue");
		Button off = new Button("Off");

		HBox layout = new HBox(20);
		layout.getChildren().addAll(red, green, blue, off);
		layout.setPadding(new Insets(20, 20, 20, 10));

		Group root = new Group();
		root.getChildren().addAll(layout);

		Pane pane = new Pane();
		pane.getChildren().addAll(root);

		// initialize action for buttons
		red.setOnAction(e -> {
			try {
				main.output.write(1);
			} catch (Exception e1) {
				// TODO Auto-generated catch block
				e1.printStackTrace();
			}
		});
		
		green.setOnAction(e ->{
			try {
				main.output.write(2);
			} catch (Exception e1) {
				// TODO Auto-generated catch block
				e1.printStackTrace();
			}
		});
		blue.setOnAction(e ->{
			try {
				main.output.write(3);
			} catch (Exception e1) {
				// TODO Auto-generated catch block
				e1.printStackTrace();
			}
		});
		off.setOnAction(e ->{
			try {
				main.output.write(7);
			} catch (Exception e1) {
				// TODO Auto-generated catch block
				e1.printStackTrace();
			}
		});
		//
		scene = new Scene(pane, 400, 150);
		window.setTitle("Serial Communication");
		window.setScene(scene);
		window.setResizable(false);
		window.show();
	}

	public static void main(String[] args) throws Exception {

		Thread t = new Thread() {
			public void run() {
				// the following line will keep this app alive for 1000 seconds,
				// waiting for events to occur and responding to them (printing
				// incoming messages to console).
				try {
					Thread.sleep(1000000);
				} catch (InterruptedException ie) {
				}
			}
		};
		t.start();
		System.out.println("Started");
		launch(args);
	}

}
