using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
using DG.Tweening;

public class BattleUnit : MonoBehaviour
{
    [SerializeField] bool isPlayerUnit;


    public Entidad Entidad {get; set;}

    Image image;
    Vector3 originalPos;
    Color originalColor;
    
    private void Awake()
    {
        image = GetComponent<Image>();
        originalPos = image.transform.localPosition;
        originalColor = image.color;
    }

    public void setup(Entidad entidad)
    {
        Entidad = entidad;
        image.sprite = Entidad.getEntidadBase.Sprite;
        playEnterAnimation();
        image.color = originalColor;
    }

    public void playEnterAnimation()
    {
        if(isPlayerUnit)
            image.transform.localPosition = new Vector3(500f, originalPos.y);
        else
            image.transform.localPosition = new Vector3(-500f, originalPos.y);
        image.transform.DOLocalMoveX(originalPos.x, 1f);
    }

    public void playAttackAnimation()
    {
        var sequence = DOTween.Sequence();
        if(isPlayerUnit)
            sequence.Append(image.transform.DOLocalMoveX(originalPos.x + 50f, 0.25f));
        else
            sequence.Append(image.transform.DOLocalMoveX(originalPos.x - 50f, 0.25f));
        sequence.Append(image.transform.DOLocalMoveX(originalPos.x, 0.25f));
    }

    public void playHitAnimation()
    {
        var Sequence = DOTween.Sequence();
        Sequence.Append(image.DOColor(Color.gray, 0.1f));
        Sequence.Append(image.DOColor(originalColor, 0.1f));
    }

    public void playFaintAnimation()
    {
        var sequence = DOTween.Sequence();
        sequence.Append(image.transform.DOLocalMoveY(originalPos.y - 150f, 0.5f));
        sequence.Join(image.DOFade(0f, 0.5f));
    }
}
