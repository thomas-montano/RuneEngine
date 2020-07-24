#include <RuneEngine.h>
#include "mainEditorWindow.h"

int main()
{
    
    rune::GameApplication* runeEditor = getGameInstance();

    getGameInstance()->getWindow()->setWindowTitle("Rune Editor");

    EditorWindow* mainEditorWindow = new EditorWindow();
    runeEditor->loadScene("Editor Window", mainEditorWindow);

    runeEditor->run();

    delete mainEditorWindow;
    delete runeEditor;
    
    return 0;

}
