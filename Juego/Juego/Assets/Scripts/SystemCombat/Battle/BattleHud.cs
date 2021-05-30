using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class BattleHud : MonoBehaviour
{
    [SerializeField] Text nameText;
    [SerializeField] HpBar hpBar;
    Entidad _entidad;

    public void setData(Entidad entidad)
    {
        _entidad = entidad;
        nameText.text = entidad.getEntidadBase.Nombre;
        hpBar.setHP((float)entidad.Vida / entidad.PuntosDeVidaMax);
    }

    public IEnumerator UpdateVida()
    {
        yield return hpBar.SetHPSmooth((float)_entidad.Vida / _entidad.PuntosDeVidaMax);
    }
}
