#include "LayerStack.h"
#include "layer.h"
#include <algorithm>


namespace RANGO {
    void layerstack::PushLayer(layer* layer){
        m_layerstack.emplace(m_layerstack.begin() + LayerInsertIndex, layer);
        LayerInsertIndex++;
    }
    void layerstack::PopLayer(layer* layer){
        auto it = std::find(m_layerstack.begin(),m_layerstack.end(),layer);
        if (it!=m_layerstack.end()){
            m_layerstack.erase(it);
            LayerInsertIndex--;
        }
    }
    void layerstack::PushOverLayer(layer* layer){
        m_layerstack.emplace_back(layer);
    }
    void layerstack::PopOverLayer(layer* layer){
        auto it = std::find(m_layerstack.begin(),m_layerstack.end(),layer);
        if (it != m_layerstack.end()){
            m_layerstack.erase(it);
        }
    }
}