#include "wccpch.h"
#include "ImGUILayer.h"
#include "imgui.h"
#include "../Core/Application.h"
#include "../Platform/OpenGL/imgui_impl_glfw.h"
#include "../Platform/OpenGL/imgui_impl_opengl3.h"

namespace WCCEngine
{
	ImGUILayer::ImGUILayer()
	{
	}

	ImGUILayer::~ImGUILayer()
	{
	}

	void ImGUILayer::OnEvent(IN BaseEvent& oEvent)
	{
	}

	bool ImGUILayer::OnAttach()
	{
		IMGUI_CHECKVERSION();
		ImGui::CreateContext();

		ImGuiIO& io = ImGui::GetIO();
		io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;

		const Application* const pApplication = Application::GetInstance();
		if (!pApplication)
		{
			WCC_CLIENT_ERROR(NULL_POINTER_EXCEPTION_MESSAGE, "pApplication");
			return false;
		}

		GLFWwindow* const pNativeWindow = static_cast<GLFWwindow*>(pApplication->GetWindow().GetNativeWindow());
		if (!pNativeWindow)
		{
			WCC_CLIENT_ERROR(NULL_POINTER_EXCEPTION_MESSAGE, "pNativeWindow");
			return false;
		}

		ImGui_ImplGlfw_InitForOpenGL(pNativeWindow, true);
		ImGui_ImplOpenGL3_Init("#version 410");

		return true;
	}

	bool ImGUILayer::OnDetach()
	{
		ImGui_ImplOpenGL3_Shutdown();
		ImGui_ImplGlfw_Shutdown();
		ImGui::DestroyContext();

		return true;
	}

	void ImGUILayer::Update(IN const GameTime& oGameTime)
	{
	}

	void ImGUILayer::Render(IN Ref<Renderer2D> pRenderer)
	{
		ImGui_ImplOpenGL3_NewFrame();
		ImGui_ImplGlfw_NewFrame();

		ImGui::NewFrame();
		ImGui::ShowDemoWindow();

		ImGui::Render();
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
	}
};
