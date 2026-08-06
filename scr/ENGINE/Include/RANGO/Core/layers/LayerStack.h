#pragma once 
#include "layer.h"
#include <vector>


namespace RANGO {
    class layerstack {
        public:
            void PushLayer(layer* layer);
            void PopLayer(layer* layer);
            void PushOverLayer(layer* layer);
            void PopOverLayer(layer* layer);
        private:
            std::vector<layer*> m_layerstack;
            unsigned int LayerInsertIndex;
    };
}