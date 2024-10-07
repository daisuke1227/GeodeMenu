#include "LabelHooks.hpp"

bool LabelsUILayer::init(GJBaseGameLayer* bgl)
{
    if (!UILayer::init(bgl))
        return false;

    if (!bgl)
        return true;

    m_fields->labelLayer = LabelLayer::create(this);

    this->addChild(m_fields->labelLayer, 69 + 1);
    return true;
}

void LabelBaseGameLayer::resetLevelVariables()
{
    GJBaseGameLayer::resetLevelVariables();

    if (LevelEditorLayer::get() ? !LevelEditorLayer::get()->m_editorUI->m_playtestStopBtn->isVisible() : true)
        as<LabelsUILayer*>(m_uiLayer)->m_fields->labelLayer->incrementAttempts();

    as<LabelsUILayer*>(m_uiLayer)->m_fields->labelLayer->resetCPS();
}

void LabelBaseGameLayer::handleButton(bool down, int button, bool isPlayer1)
{
    GJBaseGameLayer::handleButton(down, button, isPlayer1);

    if (down && button == 1)
        as<LabelsUILayer*>(m_uiLayer)->m_fields->labelLayer->increateCPS(!isPlayer1);
}