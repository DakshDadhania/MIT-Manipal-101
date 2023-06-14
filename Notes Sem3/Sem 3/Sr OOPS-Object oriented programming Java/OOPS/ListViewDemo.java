// Demonstrate a list view.
import javafx.application.*;
import javafx.scene.*;
import javafx.stage.*;
import javafx.scene.layout.*;
import javafx.scene.control.*;
import javafx.geometry.*;
import javafx.beans.value.*;
import javafx.collections.*;
public class ListViewDemo extends Application
{
   Label response;
   public static void main(String[] args) {
    // Start the JavaFX application by calling launch().
      launch(args);
     }

   // Override the start() method.
   public void start(Stage myStage) {
    // Give the stage a title.
   myStage.setTitle("ListView Demo");
   // Use a FlowPane for the root node. In this case,
   // vertical and horizontal gaps of 10.
   FlowPane rootNode = new FlowPane(10, 10);
   // Center the controls in the scene.
   rootNode.setAlignment(Pos.CENTER);
   // Create a scene.
   Scene myScene = new Scene(rootNode, 200, 120);
   // Set the scene on the stage.
   myStage.setScene(myScene);
   // Create a label.
   response = new Label("Select Computer Type");
  // Create an ObservableList of entries for the list view.
   ObservableList<String> computerTypes =
   FXCollections.observableArrayList("Smartphone", "Tablet", "Notebook",
   "Desktop" );
   // Create the list view.
   ListView<String> lvComputers = new ListView<String>(computerTypes);
   // Set the preferred height and width.
   lvComputers.setPrefSize(100, 70);
   // width and height of the ListView on the screen
   // Get the list view selection model.
   MultipleSelectionModel<String> lvSelModel =lvComputers.getSelectionModel();
   // Use a change listener to respond to a change of selection within
   // a list view.
   lvSelModel.selectedItemProperty().addListener(
   new ChangeListener<String>() {
   public void changed(ObservableValue<? extends String> changed,
   String oldVal, String newVal) {
   // Display the selection.
   response.setText("Computer selected is " + newVal);
    }
  });

  // Add the label and list view to the scene graph.
  rootNode.getChildren().addAll(lvComputers, response);
  // Show the stage and its scene.
  myStage.show();
  }
}

//listView.getSelectionModel().setSelectionMode(SelectionMode.MULTIPLE);
