#pragma once

#include "Framework/Commands/Commands.h"
#include "Templates/SharedPointer.h"

class FUICommandInfo;

class FCACommonCommands : public TCommands<FCACommonCommands>
{
public:
	FCACommonCommands();

	TSharedPtr<FUICommandInfo> SearchBT;
	TSharedPtr<FUICommandInfo> NewBlackboard;

	/** Initialize commands */
	virtual void RegisterCommands() override;
};