# ImGuiWidgets
## Introduction
This library provides a collection of visualization widgets for your project!
## Features
### Bounding Box Widget
### Perspective Frustum Widget
### Orthographic Frustum Widget
## Example
```cpp
Matrix _CamViewMatrix = Cam::GetViewMatrix();
Matrix _CamProjectionMatrix = Cam::GetProjectionMatrix();
Matrix _Matrix = Matrix::Identity;
Vector3 _Min = Vector3(-1.0f, -1.0f, -1.0f);
Vector3 _Max =  Vector3(1.0f, 1.0f, 1.0f);
float _Near = 0.1f;
float _Far = 100.0f;
float _Width = 1280.0f;
float _Height = 720.0f;
float _Fov = 45.0f;
  
ImGuizmo::DrawBoundingBox(
  (float*)&_CamViewMatrix,
  (float*)&_CamProjectionMatrix,
  (float*)&_Matrix,
  (float*)&_Min,
  (float*)&_Max);
    
ImGuizmo::DrawPerspectiveFrustum(
  (float*)&_CamViewMatrix,
  (float*)&_CamProjectionMatrix,
  (float*)&_Matrix,
  _Near,
  _Far,
  _Width,
  _Height,
  _Fov);
    
ImGuizmo::DrawOrthographicFrustum(
  (float*)&_CamViewMatrix,
  (float*)&_CamProjectionMatrix,
  (float*)&_Matrix,
  _Near,
  _Far,
  _Width,
  _Height);
}
```
## License
ImGuiWidgets is licensed under the MIT License, see [LICENSE](/LICENSE) for more information.
