#include "Fusion_View.h"
#include  "imgui.h"

namespace fv {
	Fusion_View::Fusion_View()
	{	
		imgui = new Fusion_Imgui();

	}

	Fusion_View::~Fusion_View()
	{
		delete imgui;
	}

	void Fusion_View::run()
	{

		while (!imgui->shutdown()) {
			imgui->start();
			
			// Add a layer stack of IMGUI Functions organized in the appropriate order.
			// this is odd but still  good i think !! needs more redesign. Not satisfied with the code yet
			// but its working
			//Example of how EZ it is.
			if (ImGui::BeginMainMenuBar()) {

				ImGui::EndMainMenuBar();
			}

			//Example -> you only need to call the Imgui Functions in here and you have to manage state in certain circumstances.
			imgui->showDemo();

			imgui->end();
		}
	}
}
