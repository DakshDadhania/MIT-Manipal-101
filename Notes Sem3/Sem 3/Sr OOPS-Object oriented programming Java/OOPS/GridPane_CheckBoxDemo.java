import javafx.event.ActionEvent;
import javafx.application.Application;
import javafx.event.EventHandler;
import javafx.scene.Scene;
import javafx.scene.control.*;
import javafx.scene.layout.*;
import javafx.stage.Stage;
import javafx.geometry.*;// Insets
import javafx.scene.text.Font;


public class GridPane_CheckBoxDemo extends Application{
    public static void main(String[] args){
        launch(args);
    }

   
    public void start(Stage primaryStage) {
        primaryStage.setTitle("GridPane and Checkbox Demo!");
        GridPane root=new GridPane();
        root.setAlignment(Pos.CENTER);
        //root.setMinSize(200,200);
	root.setPadding(new Insets(10));
        // Insets class stores the inside offsets for the four sides of the rectangular area. 

	root.setVgap(5);
	root.setHgap(5);

	Label response=new Label(" Welcome:Select the Languages which you can speak.");
        response.setFont(new Font("Arial", 20));

        CheckBox cbKan=new CheckBox("Kannada");
        CheckBox cbEng=new CheckBox("English");
        CheckBox cbHin=new CheckBox("Hindi");
	cbKan.setFont(new Font("Arial", 15));
	cbEng.setFont(new Font("Arial", 15));
	cbHin.setFont(new Font("Arial", 15));

        root.add(response,3,5);// control, col,row
	root.add(cbEng,3,7);
	root.add(cbKan,3,9);
	root.add(cbHin,3,11);
        primaryStage.setScene(new Scene(root, 500, 600));



        cbEng.setOnAction(new EventHandler<ActionEvent>() {
     public void handle(ActionEvent ae) {
if(cbEng.isSelected())
    response.setText("English was just selected.");
else
    response.setText("English was just cleared.");

}
});

     
        primaryStage.show();

    }
}
