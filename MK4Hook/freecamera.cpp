#include "freecamera.h"
#include <iostream>
#include "settings.h"

bool   FreeCamera::freezeCam;
Vector FreeCamera::camPos;
Vector FreeCamera::camRot;
void FreeCamera::Update()
{
    if (!eSettingsManager::bEnableFreeCamera)
        return;

    if (GetAsyncKeyState(67) & 0x1)
        freezeCam ^= 1;

    if (!freezeCam)
    {
        _get_camera_xyz(&camPos);
        _get_camera_angle(&camRot);
    }


    if (freezeCam)
    {
         ((void(__cdecl*)())0x4311D0)();
        float speed = 0.025f;
        if (GetAsyncKeyState(16))
            speed *= 2;

        if (GetAsyncKeyState(77))
            camPos.y += speed;
        if (GetAsyncKeyState(76))
            camPos.y -= speed;

        if (GetAsyncKeyState(66))
            camPos.z += speed;
        if (GetAsyncKeyState(78))
            camPos.z -= speed;

        if (GetAsyncKeyState(79))
            camPos.x += speed;
        if (GetAsyncKeyState(80))
            camPos.x -= speed;

        _set_camera_xyz(&camPos);
    }

   // printf("%f %f %f\n", camPos.x, camPos.y, camPos.z);

}


void __declspec(naked) camera_hook_one()
{
    static int j_continue = 0x40758B;
    static int _eax = 0;
    _asm {
        mov     esi, [eax + 4]
        mov _eax, eax
        pushad
    }

    if (_eax == get_camera() + 0x54 && FreeCamera::freezeCam)
    {
        _asm popad
        _asm jmp j_continue
    }
    else
    {
        _asm {
            popad
            mov eax, _eax
            mov[eax], edi
            jmp j_continue
        }
    }

}

void __declspec(naked) camera_hook_two()
{
    static int j_continue = 0x407596;
    static int _eax = 0;
    _asm {
        mov     edx, [eax + 8]
        mov _eax, eax
        pushad
    }

    if (_eax == get_camera() + 0x54 && FreeCamera::freezeCam)
    {
        _asm popad
        _asm jmp j_continue
    }
    else
    {
        _asm {
            popad
            mov eax, _eax
            mov[eax + 4], esi
            jmp j_continue
        }
    }

}


void __declspec(naked) camera_hook_three()
{
    static int j_continue = 0x40759E;
    static int _eax = 0;
    _asm {
        add     edx, ecx
        mov _eax, eax
        pushad
    }

    if (_eax == get_camera() + 0x54 && FreeCamera::freezeCam)
    {
        _asm popad
        _asm jmp j_continue
    }
    else
    {
        _asm {
            popad
            mov eax, _eax
            mov[eax + 8], edx
            jmp j_continue
        }
    }

}

void __declspec(naked) camera_angle_hook_one()
{
    static int j_continue = 0x4075D3;
    static int _esi = 0;
    _asm {
        mov     eax, ds:0x53C42C
        mov _esi, esi
        pushad
    }

    if (_esi == get_camera() + 0x60 && FreeCamera::freezeCam)
    {
        _asm popad
        _asm jmp j_continue
    }
    else
    {
        _asm {
            popad
            mov esi, _esi
            mov[esi], eax
            jmp j_continue
        }
    }

}

void __declspec(naked) camera_angle_hook_two()
{
    static int j_continue = 0x4075ED;
    static int _esi = 0;
    _asm {
        mov     edx, ds:0x53C42C
        mov _esi, esi
        pushad
    }

    if (_esi == get_camera() + 0x60 && FreeCamera::freezeCam)
    {
        _asm popad
        _asm jmp j_continue
    }
    else
    {
        _asm {
            popad
            mov esi, _esi
            mov[esi + 4], edx
            jmp j_continue
        }
    }
}

void __declspec(naked) camera_angle_hook_three()
{
    static int j_continue = 0x407607;
    static int _esi = 0;
    _asm {
        mov     ecx, ds:0x53C42C
        pop     edi
        mov _esi, esi
        pushad
    }

    if (_esi == get_camera() + 0x60 && FreeCamera::freezeCam)
    {
        _asm popad
        _asm jmp j_continue
    }
    else
    {
        _asm {
            popad
            mov esi, _esi
            mov[esi + 8], ecx
            jmp j_continue
        }
    }
}

void __declspec(naked) camera_update_hook_one()
{
    static int j_continue = 0x4326AD;
    static int _ecx = 0;
    _asm {
        mov     ds:0x53C42C, edx
        mov     _ecx, ecx
        pushad
    }

    if (_ecx == get_camera() && FreeCamera::freezeCam)
    {
        _asm {
            popad 
            jmp j_continue
        }
    }
    else
    {
        _asm {
            popad
            mov[ecx + 0x54], edx
            jmp j_continue
        }
    }
}

void __declspec(naked) camera_update_hook_two()
{
    static int j_continue = 0x4326B9;
    static int _ecx = 0;
    _asm {
        mov     ds : 0x53C42C, edx
        mov _ecx, ecx
        pushad
    }

    if (_ecx == get_camera() && FreeCamera::freezeCam)
    {
        _asm {
            popad
            jmp j_continue
        }
    }
    else
    {
        _asm {
            popad
            mov[ecx + 0x58], edx
            jmp j_continue
        }
    }
}

void __declspec(naked) camera_update_hook_three()
{
    static int j_continue = 0x4326C5;
    static int _ecx = 0;
    _asm {
        mov     ds : 0x53C42C, edx
        mov _ecx, ecx
        pushad
    }

    if (_ecx == get_camera() && FreeCamera::freezeCam)
    {
        _asm {
            popad
            jmp j_continue
        }
    }
    else
    {
        _asm {
            popad
            mov[ecx + 0x5C], edx
            jmp j_continue
        }
    }
}

void __declspec(naked) camera_update_angle_hook_one()
{
    static int j_continue = 0x4326D1;
    static int _ecx = 0;
    _asm {
        mov     ds : 0x53C42C, edx
        mov _ecx, ecx
        pushad
    }

    if (_ecx == get_camera() && FreeCamera::freezeCam)
    {
        _asm {
            popad
            jmp j_continue
        }
    }
    else
    {
        _asm {
            popad
            mov ecx, _ecx
            mov[ecx + 0x60], edx
            jmp j_continue
        }
    }
}

void __declspec(naked) camera_update_angle_hook_two()
{
    static int j_continue = 0x4326DD;
    static int _ecx = 0;
    _asm {
        mov     ds : 0x53C42C, edx
        mov _ecx, ecx
        pushad
    }

    if (_ecx == get_camera() && FreeCamera::freezeCam)
    {
        _asm {
            popad
            jmp j_continue
        }
    }
    else
    {
        _asm {
            popad
            mov ecx, _ecx
            mov[ecx + 0x64], edx
            jmp j_continue
        }
    }
}

void __declspec(naked) camera_update_angle_hook_three()
{
    static int j_continue = 0x4326E8;
    static int _ecx = 0;
    _asm {
        mov     ds : 0x53C42C, eax
        mov _ecx, ecx
        pushad
    }

    if (_ecx == get_camera() && FreeCamera::freezeCam)
    {
        _asm {
            popad
            jmp j_continue
        }
    }
    else
    {
        _asm {
            popad
            mov ecx, _ecx
            mov [ecx + 0x68], eax
            jmp j_continue
        }
    }
}

void __declspec(naked) camera_special_hook_one()
{
    static int j_continue = 0x48AE7A;
    static int _ecx = 0;
    _asm {
        mov _ecx, ecx
        pushad
    }

    if (_ecx == get_raw_camera() && FreeCamera::freezeCam)
    {
        _asm {
            popad
            jmp j_continue
        }
    }
    else
    {
        _asm {
            popad
            mov ecx, _ecx
            mov     ds : 0x58[ecx * 4], edx
            jmp j_continue
        }
    }
}

void __declspec(naked) camera_special_hook_two()
{
    static int j_continue = 0x48AE8C;
    static int _eax = 0;
    _asm {
        mov _eax, eax
        pushad
    }

    if (_eax == get_raw_camera() && FreeCamera::freezeCam)
    {
        _asm {
            popad
            jmp j_continue
        }
    }
    else
    {
        _asm {
            popad
            mov eax, _eax
            mov ds : 0x54[eax * 4], ecx
            jmp j_continue
        }
    }
}

void __declspec(naked) camera_special_hook_three()
{
    static int j_continue = 0x48AE9E;
    static int _eax = 0;
    _asm {
        mov _eax, eax
        pushad
    }

    if (_eax == get_raw_camera() && FreeCamera::freezeCam)
    {
        _asm {
            popad
            jmp j_continue
        }
    }
    else
    {
        _asm {
            popad
            mov     eax, _eax
            mov     ds : 0x5C[eax * 4], edx
            jmp j_continue
        }
    }
}

void __declspec(naked) camera_special_angle_hook_x()
{
    static int j_continue = 0x4258E7;
    static int _edx = 0;
    _asm {
        mov _edx, edx
        pushad
    }

    if (_edx == get_raw_camera() + 0x60 && FreeCamera::freezeCam)
    {
        _asm {
            popad
            jmp j_continue
        }
    }
    else
    {
        _asm {
            popad
            mov     ds : 0[edx * 4], eax
            jmp j_continue
        }
    }
}

void __declspec(naked) camera_special_angle_hook_one()
{
    static int j_continue = 0x42AF39;
    static int _edx = 0;
    _asm {
        mov _edx, ecx
        pushad
    }

    if (_edx == get_raw_camera() + 0x60 && FreeCamera::freezeCam)
    {
        _asm {
            popad
            jmp j_continue
        }
    }
    else
    {
        _asm {
            popad
            mov edx, _edx
            mov   ds : 0[edx * 4], eax
            jmp j_continue
        }
    }
}

void __declspec(naked) camera_special_angle_hook_two()
{
    static int j_continue = 0x42AF6E;
    static int _edx = 0;
    _asm {
        mov _edx, ecx
        pushad
    }

    if (_edx == get_raw_camera() + 0x60 && FreeCamera::freezeCam)
    {
        _asm {
            popad
            jmp j_continue
        }
    }
    else
    {
        _asm {
            popad
            mov edx, _edx
            mov     ds : 4[edx * 4], eax
            jmp j_continue
        }
    }
}

void __declspec(naked) camera_special_angle_hook_three()
{
    static int j_continue = 0x42AFA3;
    static int _edx = 0;
    _asm {
        mov _edx, ecx
        pushad
    }

    if (_edx == get_raw_camera() + 0x60 && FreeCamera::freezeCam)
    {
        _asm {
            popad
            jmp j_continue
        }
    }
    else
    {
        _asm {
            popad
            mov edx, _edx
            mov     ds : 8[edx * 4], eax
            jmp j_continue
        }
    }
}

void __declspec(naked) camera_special_angle2_hook_one()
{
    static int j_continue = 0x425144;
    static int _eax = 0;
    _asm {
        shl     eax, 2
        add     esi, edi
        mov _eax, eax
        pushad
    }

    if (_eax == get_camera() + 0x60 && FreeCamera::freezeCam)
    {
        _asm {
            popad
            jmp j_continue
        }
    }
    else
    {
        _asm {
            popad
            mov eax, _eax
            mov[eax], esi
            jmp j_continue
        }
    }
}

void __declspec(naked) camera_special_angle2_hook_two()
{
    static int j_continue = 0x425150;
    static int _eax = 0;
    _asm {
        mov     edi, [edx + 4]
        add     esi, edi
        pop     edi
        mov _eax, eax
        pushad
    }

    if (_eax == get_camera() + 0x60 && FreeCamera::freezeCam)
    {
        _asm {
            popad
            jmp j_continue
        }
    }
    else
    {
        _asm {
            popad
            mov eax, _eax
            mov[eax + 4], esi
            jmp j_continue
        }
    }
}

void __declspec(naked) camera_special_angle2_hook_three()
{
    static int j_continue = 0x42515C;
    static int _eax = 0;
    _asm {
        mov     esi, [ecx + 8]
        add     edx, esi
        pop     esi
        mov _eax, eax
        pushad
    }

    if (_eax == get_camera() + 0x60 && FreeCamera::freezeCam)
    {
        _asm {
            popad
            jmp j_continue
        }
    }
    else
    {
        _asm {
            popad
            mov eax, _eax
            mov[eax + 8], edx
            jmp j_continue
        }
    }
}

void __declspec(naked) camera_special_more_hook_one()
{
    static int j_continue = 0x43F207;
    static int _ecx = 0;
    _asm {
        mov _ecx, ecx
        pushad
    }

    if (_ecx == get_raw_camera() && FreeCamera::freezeCam)
    {
        _asm {
            popad
            jmp j_continue
        }
    }
    else
    {
        _asm {
            popad
            mov ecx, _ecx
            mov     ds : 0x54[ecx * 4], eax
            jmp j_continue
        }
    }
}

void __declspec(naked)  camera_special_more_hook_two()
{
    static int j_continue = 0x43F19A;
    static int _ecx = 0;
    _asm {
        mov _ecx, ecx
        pushad
    }

    if (_ecx == get_raw_camera() && FreeCamera::freezeCam)
    {
        _asm {
            popad
            jmp j_continue
        }
    }
    else
    {
        _asm {
            popad
            mov ecx, _ecx
            mov     ds : 0x5C[ecx * 4], eax
            jmp j_continue
        }
    }
}

void __declspec(naked) camera_special_more_hook_three()
{
    static int j_continue = 0x457C84;
    static int _edx = 0;
    _asm {
        mov _edx, edx
        pushad
    }

    if (_edx == get_raw_camera() && FreeCamera::freezeCam)
    {
        _asm {
            popad
            jmp j_continue
        }
    }
    else
    {
        _asm {
            popad
            mov edx, _edx
            mov     ds : 0x58[edx * 4], eax
            jmp j_continue
        }
    }
}

void __declspec(naked) camera_special_more_hook_four()
{
    static int j_continue = 0x457BEF;
    static int _edx = 0;
    _asm {
        mov _edx, edx
        pushad
    }

    if (_edx == get_raw_camera() && FreeCamera::freezeCam)
    {
        _asm {
            popad
            jmp j_continue
        }
    }
    else
    {
        _asm {
            popad
            mov edx, _edx
            mov     ds : 0x58[edx * 4], eax
            jmp j_continue
        }
    }
}

void __declspec(naked) camera_special_more_angle_hook_one()
{
    static int j_continue = 0x43F258;
    static int _edx = 0;
    _asm {
        mov _edx, edx
        pushad
    }

    if (_edx == get_raw_camera() && FreeCamera::freezeCam)
    {
        _asm {
            popad
            jmp j_continue
        }
    }
    else
    {
        _asm {
            popad
            mov edx, _edx
            mov     ds : 0x64[edx * 4], eax
            jmp j_continue
        }
    }
}

void __declspec(naked) camera_special_more_angle_hook_two()
{
    static int j_continue = 0x425863;
    static int _eax = 0;
    _asm {
        mov _eax, eax
        pushad
    }

    if (_eax == get_camera() + 0x60 && FreeCamera::freezeCam)
    {
        _asm {
            popad
            jmp j_continue
        }
    }
    else
    {
        _asm {
            popad
            mov eax, _eax
            mov     ds : 4[eax * 4], ecx
            jmp j_continue
        }
    }
}
