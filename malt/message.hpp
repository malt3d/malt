//
// Created by fatih on 4/27/17.
//

namespace malt
{
    template <class MsgT, class... Args> struct message;
    template <class MsgT, class... Args> struct message<MsgT(Args...)> {};
}
