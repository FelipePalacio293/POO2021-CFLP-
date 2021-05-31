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
    [SerializeField] GameObject[] enemigos;
    [SerializeField] AudioClip musicaAmbiental;
    [SerializeField] AudioClip musicaPelea;
    AudioSource audioSource;
    EstadoJuego estadoJuego;

    private void Start()
    {
        generarItem();
        generarEnemigo();
        player.iniciadorPeleas += iniciarBatalla;
        battleSystem.cuandoFinalicePelea += terminarPelea;
        audioSource = GetComponent<AudioSource>();
        generarItemsIniciales();
        generarEnemigosIniciales();
        audioSource.clip = musicaAmbiental;
        audioSource.Play();
    }

    public void generarItemsIniciales()
    {

    }

    public void generarEnemigosIniciales()
    {
        
    }

    public void terminarPelea(bool ganador)
    {
        estadoJuego = EstadoJuego.normal;
        camera.gameObject.SetActive(true);
        battleSystem.gameObject.SetActive(false);
        canvasDatos.SetActive(true);
        canvasInventario.worldCamera = camera;
        audioSource.clip = musicaAmbiental;
        audioSource.Play();
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
        audioSource.clip = musicaPelea;
        audioSource.Play();
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
        Invoke("generarItem", 30f);
    }

    public void generarEnemigo()
    {
        int x = Random.Range(0, transforms.Length - 1);
        int y = Random.Range(0, enemigos.Length - 1);
        Instantiate(enemigos[y], transforms[x]);
        Invoke("generarEnemigo", 5f);
    }
}
