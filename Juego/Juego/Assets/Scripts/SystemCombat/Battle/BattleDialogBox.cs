using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class BattleDialogBox : MonoBehaviour
{
    [SerializeField] Text dialogText;
    [SerializeField] int lettersPerSecond;
    [SerializeField] Color highligthtedColor;
    [SerializeField] GameObject accionSelector;
    [SerializeField] GameObject poderSelector;
    [SerializeField] GameObject pocionSelector;
    [SerializeField] List<Text> actionTexts;
    [SerializeField] List<Text> poderTexts;
    [SerializeField] List<Text> pocionTexts;
    
    public void SetDialog(string dialog)
    {
        dialogText.text = dialog;
    }

    public IEnumerator escogerDialogo(string dialog)
    {
        dialogText.text = "";
        foreach(var letter in dialog.ToCharArray())
        {
            dialogText.text += letter;
            yield return new WaitForSeconds(1f/lettersPerSecond);
        }
    }

    public void habilitarTextoDeDialogo(bool enabled)
    {
        dialogText.enabled = enabled;
    }

    public void habilitarSelectorDeAccion(bool enabled)
    {
        accionSelector.SetActive(enabled);
    }

    public void habilitarSelectorDePoder(bool enabled)
    {
        poderSelector.SetActive(enabled);
    }

    public void habilitarSelectorDePocion(bool enabled)
    {
        pocionSelector.SetActive(enabled);
    }

    public void actualizarCambioDeAccion(int accionSelected)
    {
        for(int i = 0; i < actionTexts.Count; ++i)
        {
            if(i == accionSelected)
                actionTexts[i].color = highligthtedColor;
            else
                actionTexts[i].color = Color.black;
        }
    }

    public void actualizarCambioDePoder(int poderSelected, Poder poder)
    {
        for(int i = 0; i < poderTexts.Count; ++i)
        {
            if(i == poderSelected)
                poderTexts[i].color = highligthtedColor;
            else
                poderTexts[i].color = Color.black;
        }
    }

    public void setPoderesNombre(List<Poder> poderes)
    {
        for(int i = 0; i < poderTexts.Count; ++i)
        {
            if(i < poderes.Count)
                poderTexts[i].text = poderes[i].Base.Nombre;
            else
                poderTexts[i].text = "-";
        }
    }

    public void setNombresPociones(List<Item> items)
    {
        foreach(Item item in items)
        {
            switch (item.getItemType())
            {
                case Item.ItemType.pocionVida: 
                    poderTexts[0].text = "Pocion Vida";
                    break;
                case Item.ItemType.pocionDanio: 
                    poderTexts[1].text = "Pocion danio";
                    break;
                case Item.ItemType.pocionDefensa: 
                    poderTexts[2].text = "Pocion huir";
                    break;
                case Item.ItemType.pocionAumentoDanio: 
                    poderTexts[3].text = "Pocion aumento danio";
                    break;
            }
            
        }
    }
}
