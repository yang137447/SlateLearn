#include "CustomAssetCommonCommands.h"
#include "EditorStyleSet.h"

#define LOCTEXT_NAMESPACE "CustomAssetEditorCommands"
FCACommonCommands::FCACommonCommands()
	:TCommands<FCACommonCommands>("CustomAssetEditor.Common", LOCTEXT("CustomAssetEditorCommonLabel", "Custom Asset Editor"), NAME_None, FEditorStyle::GetStyleSetName())
{
}

void FCACommonCommands::RegisterCommands()
{
	UI_COMMAND(SearchBT, "Search", "Search this Behavior Tree.", EUserInterfaceActionType::Button, FInputChord(EModifierKey::Control, EKeys::F));
	UI_COMMAND(NewBlackboard, "New Blackboard", "Create a new Blackboard Data Asset", EUserInterfaceActionType::Button, FInputChord());
}

#undef LOCTEXT_NAMESPACE