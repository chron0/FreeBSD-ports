--- third_party/swiftshader/src/OpenGL/libEGL/Display.cpp.orig	2019-06-04 18:58:01 UTC
+++ third_party/swiftshader/src/OpenGL/libEGL/Display.cpp
@@ -688,7 +688,7 @@ bool Display::isValidWindow(EGLNativeWindowType window
 			return status != 0;
 		}
 		return false;
-	#elif defined(__linux__)
+	#elif defined(__linux__) || defined(__FreeBSD__)
 		return false;  // Non X11 linux is headless only
 	#elif defined(__APPLE__)
 		return sw::OSX::IsValidWindow(window);
@@ -866,7 +866,7 @@ sw::Format Display::getDisplayFormat() const
 		{
 			return sw::FORMAT_X8R8G8B8;
 		}
-	#elif defined(__linux__)  // Non X11 linux is headless only
+	#elif defined(__linux__) || defined(__FreeBSD__) // Non X11 linux is headless only
 		return sw::FORMAT_A8B8G8R8;
 	#elif defined(__APPLE__)
 		return sw::FORMAT_A8B8G8R8;
