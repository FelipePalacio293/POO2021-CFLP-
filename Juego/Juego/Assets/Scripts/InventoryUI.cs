using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
using TMPro;
using CodeMonkey.Utils;

public class InventoryUI : MonoBehaviour
{
    private Inventario inventario;
    private Transform itemSlotContainer;
    private Transform itemSlotTemplate;

    private void Awake()
    {
        itemSlotContainer = transform.Find("itemSlotContainer");
        itemSlotTemplate = itemSlotContainer.Find("itemSlotTemplate");
        
    }

    public void setInventario(Inventario inventario)
    {
        this.inventario = inventario;
        inventario.siLaListaCambia += Inventario_siLaListaCambia;
        refrescarItemsInventario();
    }

    public void Inventario_siLaListaCambia(object sender, System.EventArgs e)
    {
        refrescarItemsInventario();
    }

    public void refrescarItemsInventario()
    {
        foreach(Transform child in itemSlotContainer)
        {
            if (child == itemSlotTemplate) 
                continue;
            Destroy(child.gameObject);
        }
        int x = 0;
        int y = 0;
        float itemSlotSize = 75f;
        foreach(Item item in inventario.getItemList())
        {
            RectTransform itemSlotRectTransform = Instantiate(itemSlotTemplate, itemSlotContainer).GetComponent<RectTransform>();
            itemSlotRectTransform.gameObject.SetActive(true);

            itemSlotRectTransform.GetComponent<Button_UI>().ClickFunc = ()  => {
                inventario.usarItem(item);
            };
            itemSlotRectTransform.GetComponent<Button_UI>().MouseRightClickFunc = () => {
                inventario.removerItem(item);
            };

            itemSlotRectTransform.anchoredPosition = new Vector2(x * itemSlotSize, y * itemSlotSize);
            Image image = itemSlotRectTransform.Find("image").GetComponent<Image>();
            image.sprite = item.getSprite();

            TextMeshProUGUI uiText = itemSlotRectTransform.Find("text").GetComponent<TextMeshProUGUI>();
            if (item.cantidadItem > 1)
            {
                uiText.SetText(item.cantidadItem.ToString());
            }
            else
            {
                uiText.SetText("");
            }
            
            x++;
            if(x > 4)
            {
                x = 0;
                y--;
            }
        }
    }
}
