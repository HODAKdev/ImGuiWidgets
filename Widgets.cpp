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

void DrawBoundingBox(
    const float* _View,
    const float* _Projection,
    const float* _Matrix,
    const float* _Min,
    const float* _Max)
    {
       matrix_t viewProjection = *(matrix_t*)_View * *(matrix_t*)_Projection;
       vec_t frustum[6];
       ComputeFrustumPlanes(frustum, viewProjection.m16);
       matrix_t res = *(matrix_t*)_Matrix * viewProjection;

       float thickness = 2.f;
       ImU32 col = IM_COL32(0xE2, 0x52, 0x52, 0xFF);

       vec_t camSpacePosition;
       camSpacePosition.TransformPoint(makeVect(0.f, 0.f, 0.f), gContext.mMVP);
       if (!gContext.mIsOrthographic && camSpacePosition.z < 1.5f)
           return;

       {
           vec_t ptA = makeVect(_Min[0], _Min[1], _Min[2]);
           vec_t ptB = makeVect(_Max[0], _Min[1], _Min[2]);
           gContext.mDrawList->AddLine(worldToPos(ptA, res), worldToPos(ptB, res), col, thickness);
       }

       {
           vec_t ptA = makeVect(_Min[0], _Min[1], _Min[2]);
           vec_t ptB = makeVect(_Min[0], _Max[1], _Min[2]);
           gContext.mDrawList->AddLine(worldToPos(ptA, res), worldToPos(ptB, res), col, thickness);
       }

       {
           vec_t ptA = makeVect(_Min[0], _Min[1], _Min[2]);
           vec_t ptB = makeVect(_Min[0], _Min[1], _Max[2]);
           gContext.mDrawList->AddLine(worldToPos(ptA, res), worldToPos(ptB, res), col, thickness);
       }

       {
           vec_t ptA = makeVect(_Min[0], _Max[1], _Min[2]);
           vec_t ptB = makeVect(_Max[0], _Max[1], _Min[2]);
           gContext.mDrawList->AddLine(worldToPos(ptA, res), worldToPos(ptB, res), col, thickness);
       }

       {
           vec_t ptA = makeVect(_Max[0], _Max[1], _Min[2]);
           vec_t ptB = makeVect(_Max[0], _Min[1], _Min[2]);
           gContext.mDrawList->AddLine(worldToPos(ptA, res), worldToPos(ptB, res), col, thickness);
       }

       {
           vec_t ptA = makeVect(_Max[0], _Min[1], _Min[2]);
           vec_t ptB = makeVect(_Max[0], _Min[1], _Max[2]);
           gContext.mDrawList->AddLine(worldToPos(ptA, res), worldToPos(ptB, res), col, thickness);
       }

       {
           vec_t ptA = makeVect(_Max[0], _Max[1], _Min[2]);
           vec_t ptB = makeVect(_Max[0], _Max[1], _Max[2]);
           gContext.mDrawList->AddLine(worldToPos(ptA, res), worldToPos(ptB, res), col, thickness);
       }

       {
           vec_t ptA = makeVect(_Min[0], _Max[1], _Min[2]);
           vec_t ptB = makeVect(_Min[0], _Max[1], _Max[2]);
           gContext.mDrawList->AddLine(worldToPos(ptA, res), worldToPos(ptB, res), col, thickness);
       }

       {
           vec_t ptA = makeVect(_Min[0], _Max[1], _Max[2]);
           vec_t ptB = makeVect(_Max[0], _Max[1], _Max[2]);
           gContext.mDrawList->AddLine(worldToPos(ptA, res), worldToPos(ptB, res), col, thickness);
       }

       {
           vec_t ptA = makeVect(_Min[0], _Max[1], _Max[2]);
           vec_t ptB = makeVect(_Min[0], _Min[1], _Max[2]);
           gContext.mDrawList->AddLine(worldToPos(ptA, res), worldToPos(ptB, res), col, thickness);
       }

       {
           vec_t ptA = makeVect(_Min[0], _Min[1], _Max[2]);
           vec_t ptB = makeVect(_Max[0], _Min[1], _Max[2]);
           gContext.mDrawList->AddLine(worldToPos(ptA, res), worldToPos(ptB, res), col, thickness);
       }

       {
           vec_t ptA = makeVect(_Max[0], _Max[1], _Max[2]);
           vec_t ptB = makeVect(_Max[0], _Min[1], _Max[2]);
           gContext.mDrawList->AddLine(worldToPos(ptA, res), worldToPos(ptB, res), col, thickness);
       }
   }

void DrawPerspectiveFrustum(
    const float* _View,
    const float* _Projection,
    const float* _Matrix,
    const float _Near,
    const float _Far,
    const float _Width,
    const float _Height,
    const float _Fov)
    {
       matrix_t viewProjection = *(matrix_t*)_View * *(matrix_t*)_Projection;
       vec_t frustum[6];
       ComputeFrustumPlanes(frustum, viewProjection.m16);
       matrix_t res = *(matrix_t*)_Matrix * viewProjection;

       float thickness = 2.f;
       ImU32 col = IM_COL32(0xE2, 0x52, 0x52, 0xFF);

       float Hnear = 2 * tan((_Fov * DEG2RAD) / 2) * _Near;
       float Wnear = Hnear * _Width / _Height;
       float Hfar = 2 * tan((_Fov * DEG2RAD) / 2) * _Far;
       float Wfar = Hfar * _Width / _Height;

       vec_t camSpacePosition;
       camSpacePosition.TransformPoint(makeVect(0.f, 0.f, 0.f), gContext.mMVP);
       if (!gContext.mIsOrthographic && camSpacePosition.z < 1.5f)
           return;

       {
           vec_t ptA = makeVect(-Wnear, Hnear, _Near);
           vec_t ptB = makeVect(Wnear, Hnear, _Near);
           gContext.mDrawList->AddLine(worldToPos(ptA, res), worldToPos(ptB, res), col, thickness);
       }

       {
           vec_t ptA = makeVect(Wnear, Hnear, _Near);
           vec_t ptB = makeVect(Wnear, -Hnear, _Near);
           gContext.mDrawList->AddLine(worldToPos(ptA, res), worldToPos(ptB, res), col, thickness);
       }

       {
           vec_t ptA = makeVect(Wnear, -Hnear, _Near);
           vec_t ptB = makeVect(-Wnear, -Hnear, _Near);
           gContext.mDrawList->AddLine(worldToPos(ptA, res), worldToPos(ptB, res), col, thickness);
       }

       {
           vec_t ptA = makeVect(-Wnear, -Hnear, _Near);
           vec_t ptB = makeVect(-Wnear, Hnear, _Near);
           gContext.mDrawList->AddLine(worldToPos(ptA, res), worldToPos(ptB, res), col, thickness);
       }

       {
           vec_t ptA = makeVect(-Wnear, Hnear, _Near);
           vec_t ptB = makeVect(-Wfar, Hfar, _Far);
           gContext.mDrawList->AddLine(worldToPos(ptA, res), worldToPos(ptB, res), col, thickness);
       }

       {
           vec_t ptA = makeVect(Wnear, Hnear, _Near);
           vec_t ptB = makeVect(Wfar, Hfar, _Far);
           gContext.mDrawList->AddLine(worldToPos(ptA, res), worldToPos(ptB, res), col, thickness);
       }

       {
           vec_t ptA = makeVect(Wnear, -Hnear, _Near);
           vec_t ptB = makeVect(Wfar, -Hfar, _Far);
           gContext.mDrawList->AddLine(worldToPos(ptA, res), worldToPos(ptB, res), col, thickness);
       }

       {
           vec_t ptA = makeVect(-Wnear, -Hnear, _Near);
           vec_t ptB = makeVect(-Wfar, -Hfar, _Far);
           gContext.mDrawList->AddLine(worldToPos(ptA, res), worldToPos(ptB, res), col, thickness);
       }

       {
           vec_t ptA = makeVect(-Wfar, Hfar, _Far);
           vec_t ptB = makeVect(Wfar, Hfar, _Far);
           gContext.mDrawList->AddLine(worldToPos(ptA, res), worldToPos(ptB, res), col, thickness);
       }

       {
           vec_t ptA = makeVect(Wfar, Hfar, _Far);
           vec_t ptB = makeVect(Wfar, -Hfar, _Far);
           gContext.mDrawList->AddLine(worldToPos(ptA, res), worldToPos(ptB, res), col, thickness);
       }

       {
           vec_t ptA = makeVect(Wfar, -Hfar, _Far);
           vec_t ptB = makeVect(-Wfar, -Hfar, _Far);
           gContext.mDrawList->AddLine(worldToPos(ptA, res), worldToPos(ptB, res), col, thickness);
       }

       {
           vec_t ptA = makeVect(-Wfar, -Hfar, _Far);
           vec_t ptB = makeVect(-Wfar, Hfar, _Far);
           gContext.mDrawList->AddLine(worldToPos(ptA, res), worldToPos(ptB, res), col, thickness);
       }

       {
           vec_t ptA = makeVect(0.0f, 0.0f, 0.0f);
           vec_t ptB = makeVect(-Wnear, Hnear, _Near);
           gContext.mDrawList->AddLine(worldToPos(ptA, res), worldToPos(ptB, res), col, thickness);
       }

       {
           vec_t ptA = makeVect(0.0f, 0.0f, 0.0f);
           vec_t ptB = makeVect(Wnear, Hnear, _Near);
           gContext.mDrawList->AddLine(worldToPos(ptA, res), worldToPos(ptB, res), col, thickness);
       }

       {
           vec_t ptA = makeVect(0.0f, 0.0f, 0.0f);
           vec_t ptB = makeVect(Wnear, -Hnear, _Near);
           gContext.mDrawList->AddLine(worldToPos(ptA, res), worldToPos(ptB, res), col, thickness);
       }

       {
           vec_t ptA = makeVect(0.0f, 0.0f, 0.0f);
           vec_t ptB = makeVect(-Wnear, -Hnear, _Near);
           gContext.mDrawList->AddLine(worldToPos(ptA, res), worldToPos(ptB, res), col, thickness);
       }
   }

void DrawOrthographicFrustum(
    const float* _View,
    const float* _Projection,
    const float* _Matrix,
    const float _Near,
    const float _Far,
    const float _Width,
    const float _Height)
    {
       matrix_t viewProjection = *(matrix_t*)_View * *(matrix_t*)_Projection;
       vec_t frustum[6];
       ComputeFrustumPlanes(frustum, viewProjection.m16);
       matrix_t res = *(matrix_t*)_Matrix * viewProjection;

       float thickness = 2.f;
       ImU32 col = IM_COL32(0xE2, 0x52, 0x52, 0xFF);

       vec_t camSpacePosition;
       camSpacePosition.TransformPoint(makeVect(0.f, 0.f, 0.f), gContext.mMVP);
       if (!gContext.mIsOrthographic && camSpacePosition.z < 1.5f)
           return;

       if (_Near != 0.0f)
       {
           {
               vec_t ptA = makeVect(0.0f, 0.0f, 0.0f);
               vec_t ptB = makeVect(_Width, _Height, _Near);
               gContext.mDrawList->AddLine(worldToPos(ptA, res), worldToPos(ptB, res), col, thickness);
           }

           {
               vec_t ptA = makeVect(0.0f, 0.0f, 0.0f);
               vec_t ptB = makeVect(_Width, -_Height, _Near);
               gContext.mDrawList->AddLine(worldToPos(ptA, res), worldToPos(ptB, res), col, thickness);
           }

           {
               vec_t ptA = makeVect(0.0f, 0.0f, 0.0f);
               vec_t ptB = makeVect(-_Width, -_Height, _Near);
               gContext.mDrawList->AddLine(worldToPos(ptA, res), worldToPos(ptB, res), col, thickness);
           }

           {
               vec_t ptA = makeVect(0.0f, 0.0f, 0.0f);
               vec_t ptB = makeVect(-_Width, _Height, _Near);
               gContext.mDrawList->AddLine(worldToPos(ptA, res), worldToPos(ptB, res), col, thickness);
           }
       }

       {
           vec_t ptA = makeVect(-_Width, _Height, _Near);
           vec_t ptB = makeVect(_Width, _Height, _Near);
           gContext.mDrawList->AddLine(worldToPos(ptA, res), worldToPos(ptB, res), col, thickness);
       }

       {
           vec_t ptA = makeVect(_Width, _Height, _Near);
           vec_t ptB = makeVect(_Width, -_Height, _Near);
           gContext.mDrawList->AddLine(worldToPos(ptA, res), worldToPos(ptB, res), col, thickness);
       }

       {
           vec_t ptA = makeVect(_Width, -_Height, _Near);
           vec_t ptB = makeVect(-_Width, -_Height, _Near);
           gContext.mDrawList->AddLine(worldToPos(ptA, res), worldToPos(ptB, res), col, thickness);
       }

       {
           vec_t ptA = makeVect(-_Width, -_Height, _Near);
           vec_t ptB = makeVect(-_Width, _Height, _Near);
           gContext.mDrawList->AddLine(worldToPos(ptA, res), worldToPos(ptB, res), col, thickness);
       }

       {
           vec_t ptA = makeVect(-_Width, _Height, _Far);
           vec_t ptB = makeVect(_Width, _Height, _Far);
           gContext.mDrawList->AddLine(worldToPos(ptA, res), worldToPos(ptB, res), col, thickness);
       }

       {
           vec_t ptA = makeVect(_Width, _Height, _Far);
           vec_t ptB = makeVect(_Width, -_Height, _Far);
           gContext.mDrawList->AddLine(worldToPos(ptA, res), worldToPos(ptB, res), col, thickness);
       }

       {
           vec_t ptA = makeVect(_Width, -_Height, _Far);
           vec_t ptB = makeVect(-_Width, -_Height, _Far);
           gContext.mDrawList->AddLine(worldToPos(ptA, res), worldToPos(ptB, res), col, thickness);
       }

       {
           vec_t ptA = makeVect(-_Width, -_Height, _Far);
           vec_t ptB = makeVect(-_Width, _Height, _Far);
           gContext.mDrawList->AddLine(worldToPos(ptA, res), worldToPos(ptB, res), col, thickness);
       }

       {
           vec_t ptA = makeVect(-_Width, _Height, _Near);
           vec_t ptB = makeVect(-_Width, _Height, _Far);
           gContext.mDrawList->AddLine(worldToPos(ptA, res), worldToPos(ptB, res), col, thickness);
       }

       {
           vec_t ptA = makeVect(_Width, _Height, _Near);
           vec_t ptB = makeVect(_Width, _Height, _Far);
           gContext.mDrawList->AddLine(worldToPos(ptA, res), worldToPos(ptB, res), col, thickness);
       }

       {
           vec_t ptA = makeVect(_Width, -_Height, _Near);
           vec_t ptB = makeVect(_Width, -_Height, _Far);
           gContext.mDrawList->AddLine(worldToPos(ptA, res), worldToPos(ptB, res), col, thickness);
       }

       {
           vec_t ptA = makeVect(-_Width, -_Height, _Near);
           vec_t ptB = makeVect(-_Width, -_Height, _Far);
           gContext.mDrawList->AddLine(worldToPos(ptA, res), worldToPos(ptB, res), col, thickness);
       }
   }
