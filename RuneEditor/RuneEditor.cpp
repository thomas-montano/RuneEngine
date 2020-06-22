#include <RuneEngine.h>
#include "mainEditorWindow.h"

int main()
{
    
    rune::GameApplication* runeEditor = new rune::GameApplication("Rune Engine");

    EditorWindow* mainEditorWindow = new EditorWindow();
    runeEditor->loadScene(mainEditorWindow);

    runeEditor->run();

    delete mainEditorWindow;
    delete runeEditor;
    
    return 0;

}
