#include "tunnel.h"

Tunnel::Tunnel(){

}

Tunnel::Tunnel(KnownPeer* _firstPeer){
    routers.append(_firstPeer);
}

KnownPeer* Tunnel::getRouter(int i){
    return routers[i];
}
