// MIT License

// Copyright (c) 2023 Hodak

// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:

// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

   IMGUI_API void DrawBoundingBox(
       const float* _View,
       const float* _Projection,
       const float* _Matrix,
       const float* _Min,
       const float* _Max);
   IMGUI_API void DrawPerspectiveFrustum(
       const float* _View,
       const float* _Projection,
       const float* _Matrix,
       const float _Near,
       const float _Far,
       const float _Width,
       const float _Height,
       const float _Fov);
   IMGUI_API void DrawOrthographicFrustum(
       const float* _View,
       const float* _Projection,
       const float* _Matrix,
       const float _Near,
       const float _Far,
       const float _Width,
       const float _Height);
