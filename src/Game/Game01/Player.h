#pragma once
#include <System/Scene.h>
#include <System/Component/ComponentModel.h>
#include <System/Component/ComponentCollisionModel.h>
#include <System/Component/ComponentCollisionCapsule.h>
#include <System/Component/ComponentObjectController.h>
#include <System/Component/ComponentCollisionSphere.h>
namespace Game01 {

USING_PTR(Player);

class Player : public Object
{
public:
    BP_OBJECT_DECL(Player, u8"Game01のPlayer");

    bool Init() override;

    //! @brief 更新
    void Update() override;
    void Draw() override;
    void OnHit(const ComponentCollision::HitInfo& hit_info) override;

private:
    float3 rot_;
    float  jump_power_ = 2.0f;
    bool   is_jump_    = false;
};

}    // namespace Game01
