   void DrawBoundingBox(const float* _View,
                        const float* _Projection,
                        const float* _Matrix,
                        const float* _Min,
                        const float* _Max)
   {
       matrix_t viewProjection = *(matrix_t*)view * *(matrix_t*)projection;
       vec_t frustum[6];
       ComputeFrustumPlanes(frustum, viewProjection.m16);
       matrix_t res = *(matrix_t*)matrix * viewProjection;

       float thickness = 2.f;
       ImU32 col = IM_COL32(0xE2, 0x52, 0x52, 0xFF);

       vec_t camSpacePosition;
       camSpacePosition.TransformPoint(makeVect(0.f, 0.f, 0.f), gContext.mMVP);
       if (!gContext.mIsOrthographic && camSpacePosition.z < 1.5f)
           return;

       {
           vec_t ptA = makeVect(min[0], min[1], min[2]);
           vec_t ptB = makeVect(max[0], min[1], min[2]);
           gContext.mDrawList->AddLine(worldToPos(ptA, res), worldToPos(ptB, res), col, thickness);
       }

       {
           vec_t ptA = makeVect(min[0], min[1], min[2]);
           vec_t ptB = makeVect(min[0], max[1], min[2]);
           gContext.mDrawList->AddLine(worldToPos(ptA, res), worldToPos(ptB, res), col, thickness);
       }

       {
           vec_t ptA = makeVect(min[0], min[1], min[2]);
           vec_t ptB = makeVect(min[0], min[1], max[2]);
           gContext.mDrawList->AddLine(worldToPos(ptA, res), worldToPos(ptB, res), col, thickness);
       }

       {
           vec_t ptA = makeVect(min[0], max[1], min[2]);
           vec_t ptB = makeVect(max[0], max[1], min[2]);
           gContext.mDrawList->AddLine(worldToPos(ptA, res), worldToPos(ptB, res), col, thickness);
       }

       {
           vec_t ptA = makeVect(max[0], max[1], min[2]);
           vec_t ptB = makeVect(max[0], min[1], min[2]);
           gContext.mDrawList->AddLine(worldToPos(ptA, res), worldToPos(ptB, res), col, thickness);
       }

       {
           vec_t ptA = makeVect(max[0], min[1], min[2]);
           vec_t ptB = makeVect(max[0], min[1], max[2]);
           gContext.mDrawList->AddLine(worldToPos(ptA, res), worldToPos(ptB, res), col, thickness);
       }

       {
           vec_t ptA = makeVect(max[0], max[1], min[2]);
           vec_t ptB = makeVect(max[0], max[1], max[2]);
           gContext.mDrawList->AddLine(worldToPos(ptA, res), worldToPos(ptB, res), col, thickness);
       }

       {
           vec_t ptA = makeVect(min[0], max[1], min[2]);
           vec_t ptB = makeVect(min[0], max[1], max[2]);
           gContext.mDrawList->AddLine(worldToPos(ptA, res), worldToPos(ptB, res), col, thickness);
       }

       {
           vec_t ptA = makeVect(min[0], max[1], max[2]);
           vec_t ptB = makeVect(max[0], max[1], max[2]);
           gContext.mDrawList->AddLine(worldToPos(ptA, res), worldToPos(ptB, res), col, thickness);
       }

       {
           vec_t ptA = makeVect(min[0], max[1], max[2]);
           vec_t ptB = makeVect(min[0], min[1], max[2]);
           gContext.mDrawList->AddLine(worldToPos(ptA, res), worldToPos(ptB, res), col, thickness);
       }

       {
           vec_t ptA = makeVect(min[0], min[1], max[2]);
           vec_t ptB = makeVect(max[0], min[1], max[2]);
           gContext.mDrawList->AddLine(worldToPos(ptA, res), worldToPos(ptB, res), col, thickness);
       }

       {
           vec_t ptA = makeVect(max[0], max[1], max[2]);
           vec_t ptB = makeVect(max[0], min[1], max[2]);
           gContext.mDrawList->AddLine(worldToPos(ptA, res), worldToPos(ptB, res), col, thickness);
       }
   }

   void DrawPerspectiveFrustum(const float* _View,
                               const float* _Projection,
                               const float* _Matrix,
                               const float _Near,
                               const float _Far,
                               const float _Width,
                               const float _Height,
                               const float _Fov)
   {
       matrix_t viewProjection = *(matrix_t*)view * *(matrix_t*)projection;
       vec_t frustum[6];
       ComputeFrustumPlanes(frustum, viewProjection.m16);
       matrix_t res = *(matrix_t*)matrix * viewProjection;

       float thickness = 2.f;
       ImU32 col = IM_COL32(0xE2, 0x52, 0x52, 0xFF);

       float Hnear = 2 * tan((fov * DEG2RAD) / 2) * NearZ;
       float Wnear = Hnear * width / height;

       float Hfar = 2 * tan((fov * DEG2RAD) / 2) * FarZ;
       float Wfar = Hfar * width / height;

       {
           vec_t ptA = makeVect(-Wnear, Hnear, NearZ);
           vec_t ptB = makeVect(Wnear, Hnear, NearZ);
           gContext.mDrawList->AddLine(worldToPos(ptA, res), worldToPos(ptB, res), col, thickness);
       }

       {
           vec_t ptA = makeVect(Wnear, Hnear, NearZ);
           vec_t ptB = makeVect(Wnear, -Hnear, NearZ);
           gContext.mDrawList->AddLine(worldToPos(ptA, res), worldToPos(ptB, res), col, thickness);
       }

       {
           vec_t ptA = makeVect(Wnear, -Hnear, NearZ);
           vec_t ptB = makeVect(-Wnear, -Hnear, NearZ);
           gContext.mDrawList->AddLine(worldToPos(ptA, res), worldToPos(ptB, res), col, thickness);
       }

       {
           vec_t ptA = makeVect(-Wnear, -Hnear, NearZ);
           vec_t ptB = makeVect(-Wnear, Hnear, NearZ);
           gContext.mDrawList->AddLine(worldToPos(ptA, res), worldToPos(ptB, res), col, thickness);
       }

       {
           vec_t ptA = makeVect(-Wnear, Hnear, NearZ);
           vec_t ptB = makeVect(-Wfar, Hfar, FarZ);
           gContext.mDrawList->AddLine(worldToPos(ptA, res), worldToPos(ptB, res), col, thickness);
       }

       {
           vec_t ptA = makeVect(Wnear, Hnear, NearZ);
           vec_t ptB = makeVect(Wfar, Hfar, FarZ);
           gContext.mDrawList->AddLine(worldToPos(ptA, res), worldToPos(ptB, res), col, thickness);
       }

       {
           vec_t ptA = makeVect(Wnear, -Hnear, NearZ);
           vec_t ptB = makeVect(Wfar, -Hfar, FarZ);
           gContext.mDrawList->AddLine(worldToPos(ptA, res), worldToPos(ptB, res), col, thickness);
       }

       {
           vec_t ptA = makeVect(-Wnear, -Hnear, NearZ);
           vec_t ptB = makeVect(-Wfar, -Hfar, FarZ);
           gContext.mDrawList->AddLine(worldToPos(ptA, res), worldToPos(ptB, res), col, thickness);
       }

       {
           vec_t ptA = makeVect(-Wfar, Hfar, FarZ);
           vec_t ptB = makeVect(Wfar, Hfar, FarZ);
           gContext.mDrawList->AddLine(worldToPos(ptA, res), worldToPos(ptB, res), col, thickness);
       }

       {
           vec_t ptA = makeVect(Wfar, Hfar, FarZ);
           vec_t ptB = makeVect(Wfar, -Hfar, FarZ);
           gContext.mDrawList->AddLine(worldToPos(ptA, res), worldToPos(ptB, res), col, thickness);
       }

       {
           vec_t ptA = makeVect(Wfar, -Hfar, FarZ);
           vec_t ptB = makeVect(-Wfar, -Hfar, FarZ);
           gContext.mDrawList->AddLine(worldToPos(ptA, res), worldToPos(ptB, res), col, thickness);
       }

       {
           vec_t ptA = makeVect(-Wfar, -Hfar, FarZ);
           vec_t ptB = makeVect(-Wfar, Hfar, FarZ);
           gContext.mDrawList->AddLine(worldToPos(ptA, res), worldToPos(ptB, res), col, thickness);
       }

       {
           vec_t ptA = makeVect(0.0f, 0.0f, 0.0f);
           vec_t ptB = makeVect(-Wnear, Hnear, NearZ);
           gContext.mDrawList->AddLine(worldToPos(ptA, res), worldToPos(ptB, res), col, thickness);
       }

       {
           vec_t ptA = makeVect(0.0f, 0.0f, 0.0f);
           vec_t ptB = makeVect(Wnear, Hnear, NearZ);
           gContext.mDrawList->AddLine(worldToPos(ptA, res), worldToPos(ptB, res), col, thickness);
       }

       {
           vec_t ptA = makeVect(0.0f, 0.0f, 0.0f);
           vec_t ptB = makeVect(Wnear, -Hnear, NearZ);
           gContext.mDrawList->AddLine(worldToPos(ptA, res), worldToPos(ptB, res), col, thickness);
       }

       {
           vec_t ptA = makeVect(0.0f, 0.0f, 0.0f);
           vec_t ptB = makeVect(-Wnear, -Hnear, NearZ);
           gContext.mDrawList->AddLine(worldToPos(ptA, res), worldToPos(ptB, res), col, thickness);
       }
   }

   void DrawOrthographicFrustum(const float* _View,
                                const float* _Projection,
                                const float* _Matrix,
                                const float _Near,
                                const float _Far,
                                const float _Width,
                                const float _Height)
   {
       matrix_t viewProjection = *(matrix_t*)view * *(matrix_t*)projection;
       vec_t frustum[6];
       ComputeFrustumPlanes(frustum, viewProjection.m16);
       matrix_t res = *(matrix_t*)matrix * viewProjection;

       float thickness = 2.f;
       ImU32 col = IM_COL32(0xE2, 0x52, 0x52, 0xFF);

       if (NearZ != 0.0f)
       {
           {
               vec_t ptA = makeVect(0.0f, 0.0f, 0.0f);
               vec_t ptB = makeVect(width, height, NearZ);
               gContext.mDrawList->AddLine(worldToPos(ptA, res), worldToPos(ptB, res), col, thickness);
           }

           {
               vec_t ptA = makeVect(0.0f, 0.0f, 0.0f);
               vec_t ptB = makeVect(width, -height, NearZ);
               gContext.mDrawList->AddLine(worldToPos(ptA, res), worldToPos(ptB, res), col, thickness);
           }

           {
               vec_t ptA = makeVect(0.0f, 0.0f, 0.0f);
               vec_t ptB = makeVect(-width, -height, NearZ);
               gContext.mDrawList->AddLine(worldToPos(ptA, res), worldToPos(ptB, res), col, thickness);
           }

           {
               vec_t ptA = makeVect(0.0f, 0.0f, 0.0f);
               vec_t ptB = makeVect(-width, height, NearZ);
               gContext.mDrawList->AddLine(worldToPos(ptA, res), worldToPos(ptB, res), col, thickness);
           }
       }

       {
           vec_t ptA = makeVect(-width, height, NearZ);
           vec_t ptB = makeVect(width, height, NearZ);
           gContext.mDrawList->AddLine(worldToPos(ptA, res), worldToPos(ptB, res), col, thickness);
       }

       {
           vec_t ptA = makeVect(width, height, NearZ);
           vec_t ptB = makeVect(width, -height, NearZ);
           gContext.mDrawList->AddLine(worldToPos(ptA, res), worldToPos(ptB, res), col, thickness);
       }

       {
           vec_t ptA = makeVect(width, -height, NearZ);
           vec_t ptB = makeVect(-width, -height, NearZ);
           gContext.mDrawList->AddLine(worldToPos(ptA, res), worldToPos(ptB, res), col, thickness);
       }

       {
           vec_t ptA = makeVect(-width, -height, NearZ);
           vec_t ptB = makeVect(-width, height, NearZ);
           gContext.mDrawList->AddLine(worldToPos(ptA, res), worldToPos(ptB, res), col, thickness);
       }

       {
           vec_t ptA = makeVect(-width, height, FarZ);
           vec_t ptB = makeVect(width, height, FarZ);
           gContext.mDrawList->AddLine(worldToPos(ptA, res), worldToPos(ptB, res), col, thickness);
       }

       {
           vec_t ptA = makeVect(width, height, FarZ);
           vec_t ptB = makeVect(width, -height, FarZ);
           gContext.mDrawList->AddLine(worldToPos(ptA, res), worldToPos(ptB, res), col, thickness);
       }

       {
           vec_t ptA = makeVect(width, -height, FarZ);
           vec_t ptB = makeVect(-width, -height, FarZ);
           gContext.mDrawList->AddLine(worldToPos(ptA, res), worldToPos(ptB, res), col, thickness);
       }

       {
           vec_t ptA = makeVect(-width, -height, FarZ);
           vec_t ptB = makeVect(-width, height, FarZ);
           gContext.mDrawList->AddLine(worldToPos(ptA, res), worldToPos(ptB, res), col, thickness);
       }

       {
           vec_t ptA = makeVect(-width, height, NearZ);
           vec_t ptB = makeVect(-width, height, FarZ);
           gContext.mDrawList->AddLine(worldToPos(ptA, res), worldToPos(ptB, res), col, thickness);
       }

       {
           vec_t ptA = makeVect(width, height, NearZ);
           vec_t ptB = makeVect(width, height, FarZ);
           gContext.mDrawList->AddLine(worldToPos(ptA, res), worldToPos(ptB, res), col, thickness);
       }

       {
           vec_t ptA = makeVect(width, -height, NearZ);
           vec_t ptB = makeVect(width, -height, FarZ);
           gContext.mDrawList->AddLine(worldToPos(ptA, res), worldToPos(ptB, res), col, thickness);
       }

       {
           vec_t ptA = makeVect(-width, -height, NearZ);
           vec_t ptB = makeVect(-width, -height, FarZ);
           gContext.mDrawList->AddLine(worldToPos(ptA, res), worldToPos(ptB, res), col, thickness);
       }
   }
