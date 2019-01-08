#include "f4.hpp"

namespace f4
{

using spair  = std::pair< polynomial, polynomial >;
using spairs = std::vector< spair >;

void
update(polynomials &G, spairs &P, const polynomial &f)
{
    const auto &fLM = f.LM();

    for (const auto g : G)
    {
        const auto &gLM = g.LM();

        if (gcd(fLM, gLM).degree() == 0)
        {
        }
        else
        {
        }
    }

    //TODO: detect new pairs

    P.erase(std::remove_if(P.begin(), P.end(), [&fLM](auto &p) {
        const auto &l = p.first.LM();
        const auto &r = p.second.LM();
        const auto &m = lcm(l, r);

        return fLM | m && lcm(fLM, l) != m && lcm(fLM, r) != m;
    }));

    //TODO: append some to pairs

    G.erase(std::remove_if(G.begin(), G.end(), [&fLM](auto &g) {
        return fLM | g.LM();
    }));

    G.push_back(f);
}

void
select(spairs &P, polynomials &Ld)
{
    assert(!P.empty());

    auto p = P.cbegin();
    auto d = lcm(p->first.LM(), p->second.LM()).degree();

    for (++p; p != P.cend(); ++p)
    {
        auto t = lcm(p->first.LM(), p->second.LM()).degree();

        if (t < d)
        {
            d = t;
        }
    }

    P.erase(std::remove_if(P.begin(), P.end(), [&Ld, d](auto &p) {
        const auto m = lcm(p.first.LM(), p.second.LM());

        if (m.degree() != d)
        {
            return false;
        }

        p.first *= m / p.first.LM();
        p.second *= m / p.second.LM();

        Ld.push_back(p.first);
        Ld.push_back(p.second);
        return true;
    }));
}

void
reduction(polynomials &Ld, polynomials &G, polynomials &Fd)
{
    (void) Ld;
    (void) G;
    (void) Fd;
}

polynomials
GB(polynomials &F)
{
    polynomials G, Fd, Ld;
    spairs      P;

    for (const auto &f : F)
    {
        update(G, P, f);
    }

    while (!P.empty())
    {
        Ld.clear();
        select(P, Ld);

        Fd.clear();
        reduction(Ld, G, Fd);

        //TODO: sort Fd

        for (const auto &h : Fd)
        {
            update(G, P, h);
        }
    }

    //TODO: autoreduce

    //TODO: normalize

    return G;
}

} /* namespace f4 */
