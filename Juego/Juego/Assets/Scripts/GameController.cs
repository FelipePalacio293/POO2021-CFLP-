using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public enum EstadoJuego
{
    normal, 
    luchando
}

public class GameController : MonoBehaviour
{
    [SerializeField] Transform[] transforms;
    [SerializeField] Item[] items;
    [SerializeField] Player player;
    [SerializeField] BattleSystem battleSystem;
    [SerializeField] Camera camera;
    [SerializeField] Camera cameraSecundaria;
    [SerializeField] Canvas canvasInventario;
    [SerializeField] GameObject canvasDatos;

    EstadoJuego estadoJuego;

    private void Start()
    {
        //generarItem();
        player.iniciadorPeleas += iniciarBatalla;
        battleSystem.cuandoFinalicePelea += terminarPelea;
    }

    public void terminarPelea(bool ganador)
    {
        estadoJuego = EstadoJuego.normal;
        camera.gameObject.SetActive(true);
        battleSystem.gameObject.SetActive(false);
        canvasDatos.SetActive(true);
        canvasInventario.worldCamera = camera;
        if (ganador)
        {

        }
        else
        {

        }
    }

    public void iniciarBatalla()
    {
        estadoJuego = EstadoJuego.luchando;
        battleSystem.gameObject.SetActive(true);
        camera.gameObject.SetActive(false);
        canvasInventario.worldCamera = cameraSecundaria;
        canvasDatos.SetActive(false);

        var caballero = player.GetComponent<Caballero>();
        var enemigo = player.getEnemigoActual().GetComponent<Enemigo>();
        battleSystem.empezarPelea(caballero, enemigo);
    }

    private void Update()
    {
        if(estadoJuego == EstadoJuego.normal)
        {
            player.habilitarUpdate();
        }
        else if(estadoJuego == EstadoJuego.luchando)
        {
            battleSystem.habilitarUpdate();
        }
    }

    public void generarItem() 
    {
        int x = Random.Range(0, transforms.Length - 1);
        int y = Random.Range(0, items.Length - 1);
        ItemWorldSpawner.instanciarItem(transforms[x], items[y]);
        Invoke("generarItem", 10f);
    }
}
