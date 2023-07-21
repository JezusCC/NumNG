#include "../core/utils/utils.h"
#include "../core/entry/entrys.h"

#include "imgui4sdl2raw/imgui.h"
#include "imgui4sdl2raw/imgui_impl_sdl.h"
#include "imgui4sdl2raw/imgui_impl_sdlrenderer.h"

#include "../core/utils/eventDispatcher/event_dispatcher.h"

struct Test {
	int32 a;
};

EV_CUSTOM_EVENT_DATA_DEFINE(Test, data);

void func(void* ev) {
	auto st = ngUtils::ForceCast<EV_GET_CUSTOM_EVENT_DATA_TYPE(Test)>(ev);
	st->data.a = 10;
}

int main(int argc, char* argv[]) {

	auto env = ngCore::createNgEnviroment(argc, argv);

	ngUtils::EventDispatcher dispathcer;
	dispathcer.subscribe(ngUtils::EventType::EVENT_APPLICATION, EV_CUSTOM_EVENT_FUNCTION(func));

	EV_GET_CUSTOM_EVENT_DATA_TYPE(Test) st = { 5 };

	dispathcer.dispatch(ngUtils::EventType::EVENT_APPLICATION,&st);

	dispathcer.unsubscribe(ngUtils::EventType::EVENT_APPLICATION, EV_CUSTOM_EVENT_FUNCTION(func));

	ngCore::Window2D window("Hello", 1366, 768);

	bool show_another_window = false;
	bool my_tool_active = true;

	while (window.shouldClose() == false) {
		window.procEvent();

		// Start the Dear ImGui frame
		ImGui_ImplSDLRenderer_NewFrame();
		ImGui_ImplSDL2_NewFrame();
		ImGui::NewFrame();

		{
			static float f = 0.0f;
			static int counter = 0;

			ImGui::Begin("Hello, world!");                          // Create a window called "Hello, world!" and append into it.

			ImGui::Text("This is some useful text.");               // Display some text (you can use a format strings too)
			ImGui::Checkbox("Another Window", &show_another_window);

			ImGui::SliderFloat("float", &f, 0.0f, 1.0f);            // Edit 1 float using a slider from 0.0f to 1.0f

			if (ImGui::Button("Button"))                            // Buttons return true when clicked (most widgets return true when edited/activated)
				counter++;
			ImGui::SameLine();
			ImGui::Text("counter = %d", counter);

			ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
			ImGui::End();
		}

		if (show_another_window)
		{
			ImGui::Begin("Another Window", &show_another_window);   // Pass a pointer to our bool variable (the window will have a closing button that will clear the bool when clicked)
			ImGui::Text("Hello from another window!");
			if (ImGui::Button("Close Me"))
				show_another_window = false;
			ImGui::End();
		}

		// 创建一个带有菜单栏的名为“我的第一个工具”的窗口。
		ImGui::Begin("My First Tool", &my_tool_active, ImGuiWindowFlags_MenuBar);
		if (ImGui::BeginMenuBar())
		{
			if (ImGui::BeginMenu("File"))
			{
				if (ImGui::MenuItem("Open..", "Ctrl+O")) { /* Do stuff */ }
				if (ImGui::MenuItem("Save", "Ctrl+S")) { /* Do stuff */ }
				if (ImGui::MenuItem("Close", "Ctrl+W")) { my_tool_active = false; }
				ImGui::EndMenu();
			}
			ImGui::EndMenuBar();
		}

		// Plot some values
		const float my_values[] = { 0.2f, 0.1f, 1.0f, 0.5f, 0.9f, 2.2f };
		ImGui::PlotLines("Frame Times", my_values, IM_ARRAYSIZE(my_values));

		// 在滚动区域中显示内容
		ImGui::TextColored(ImVec4(1, 1, 0, 1), "Important Stuff");
		ImGui::BeginChild("Scrolling");
		for (int n = 0; n < 50; n++)
			ImGui::Text("%04d: Some text", n);
		ImGui::EndChild();
		ImGui::End();

		window.clearBuffer();
	}

	ngCore::destroyNgEnviroment(env);

	return 0;
}